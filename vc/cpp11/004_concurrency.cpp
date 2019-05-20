//
// Created by rui.zhou on 3/28/2019.
//
/*
 * lock 使用RAII，避免lock 不能释放
 */

#include <codech/codech_def.h>
#include <mutex>
#include <random>
#include <future>
#include <chrono>

using namespace std;

namespace {
    // Lock 基本使用 =================================================================
    void testMutex() {
        std::mutex mu;
        int val=0;
        std::lock_guard<std::mutex> lk(mu);
        val++;
    }

    void recursiveLockError() {
        std::mutex mu;
        int val=0;
        std::lock_guard<std::mutex> lk(mu);
        val++;
        auto sub=[&](){
            try {
                std::lock_guard<std::mutex> lk(mu);
                val++;
            } catch(const std::system_error& e) {
                std::cout << "Caught system_error with code " << e.code()
                          << " meaning " << e.what() << '\n';
                //resource_deadlock_would_occur
            }
        };
        sub();
    }

    void recursiveLock() {
        std::recursive_mutex mu;
        int val=0;
        std::lock_guard<std::recursive_mutex> lk(mu);
        val++;
        auto sub=[&](){
            std::lock_guard<std::recursive_mutex> lk(mu);
            val++;
        };
        sub();
    }
    void tryLock() {
        std::mutex m;
        while (m.try_lock()==false) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::lock_guard<std::mutex> lk(m, std::adopt_lock);
        // do something
    }
    // 1秒超时
    void tryLockTimeout() {
        std::timed_mutex m;
        if (m.try_lock_for(std::chrono::seconds(1))) {
            std::lock_guard<std::timed_mutex> lg(m,std::adopt_lock);
        } else {
            // unable to get lock;
        }
    }

    void lock2Items() {
        std::mutex m1,m2;
        int idx = std::try_lock(m1,m2);
        //-1 on success, or 0-based index value of the object that failed to lock.
        if (idx<0) {
            std::lock_guard<std::mutex> lk1(m1,std::adopt_lock);  //必须使用lock_guard，否则lock不会被释放
            std::lock_guard<std::mutex> lk2(m2,std::adopt_lock);
        } else {
            std::cerr << "unable to lock mutex m" << idx+1 <<endl;
        }
    }

    void uniqueLock() {
        std::mutex m;
        std::unique_lock<std::mutex> lk(m, std::try_to_lock);
        if (lk) { //bool()
            std::cout << "locked" << endl;
        } else {
            std::cout << "unable to lock" << endl;
        }

        if (lk.owns_lock()) {
            std::cout << "locked" << endl;
        } else {
            std::cout << "unable to lock" << endl;
        }
    }
    // End of Lock 基本使用 =================================================================
    // future =================================
    int print_char(char c)
    {
        // random-number generator (use c as seed to get different sequences)
        cout << "thread ID " << this_thread::get_id() << endl;
        this_thread::sleep_for(2s);

        default_random_engine dre(c);
        uniform_int_distribution<int> id(10, 1000);

        // loop to print character after a random period of time
        for (int i = 0; i < 100000; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
        return c;
    }

    // policy defered 必须通过get来取得异步任务结果
    void test_future1() {
        cout << "test_future1 thread ID " << this_thread::get_id() << endl;

        std::future<int> f1 = std::async(std::launch::deferred,
                                         [] { return print_char('.'); }); // move ctor
        //wait & get can force to start task
        // but wait_for() doesn't

        future_status fs1 = f1.wait_for(chrono::seconds(10));
        if (fs1 == future_status::deferred) {
            cout << " deferred =" << int(fs1) << endl;
        }
        this_thread::sleep_for(chrono::seconds(10));
        cout << "sleep 10s complete" <<endl;

        //f1.wait();
        //f1.get();//wait?

    }
    // 不指定策略的话， 取决于runtime来决定如何运行异步任务
    void test_future2() {
        cout << "test_future2 thread ID " << this_thread::get_id() << endl;

        std::future<int> f1 = std::async([] { return print_char('.'); });
        std::future<int> f2 = std::async([] { return print_char('+'); });
        if (f1.wait_for(chrono::seconds(0)) ==future_status::deferred) {
            cout << "f1 is deferred policy" << endl;
        }

        if (f2.wait_for(chrono::seconds(0)) ==future_status::deferred) {
            cout << "f2 is deferred policy" << endl;
        }

        if (f1.wait_for(chrono::seconds(0)) !=future_status::deferred ||
            f2.wait_for(chrono::seconds(0)) !=future_status::deferred) {
            while (f1.wait_for(chrono::seconds(0)) != future_status::ready &&
                   f2.wait_for(chrono::seconds(0)) != future_status::ready ) {
                this_thread::yield();
            }
        }

        // at least one task complete
        cout.put('\n').flush();
        cout << "at least one task complete" << endl;
        try {
            f1.get();
            f2.get();
        } catch (const exception &e) {
            cout << "\nEXCEPTION:" << e.what() << endl;
        }
        cout << "\n done" << endl;

    }

    // 指定launch::async
    void test_future3() {
        cout << "thread ID " << this_thread::get_id() << endl;
        std::async(std::launch::async, [] { return print_char('.'); });  //block on dtor
        std::async(std::launch::async, [] { return print_char('+'); });
    }


    void test_future4() {
        cout << "starting 2 operations asynchronously" << endl;

        // start two loops in the background printing characters . or +
        std::future<int> f1 = std::async(std::launch::async,
                                         [] { return print_char('.'); });
        std::shared_future<int> sf = f1.share();
        auto check = [](std::shared_future<int> ready_fut) {
            cout << ready_fut.get() << endl;
        };

        std::thread t([](auto sf) {
            while (true) {
                cout << "running " << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
         },sf);

        t.detach();


//        for (int i=0;i<5;i++) {
//            check(sf);
//        }

//        cout << typeid(f1).name() << endl;
//        cout << "\nfuture test done" << endl;
//        test_future1();
//        exit(1);

    }

    // --------------------------------------------------
    //packaged_task
    void task_lambda()
    {
        std::packaged_task<int(int,int)> task([](int a, int b) {
            cout << "lambda thread ID " << this_thread::get_id() << endl;
            return std::pow(a, b);
        });
        std::future<int> result = task.get_future();
        cout << "main thread ID " << this_thread::get_id() << endl;
        task(2, 9); // 必须手动触发
        std::cout << "task_lambda:\t" << result.get() << '\n';
    }



    // promise =================================
    // caller中初始化promise, 将promise 对象传递到callee 线程对象中，由callee来设置promise的值(返回给caller)
    void promise_thread_sync_flag(std::promise<void> barrier)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        barrier.set_value();
    }

    void test_promise_sync() {
        std::promise<void> barrier;
        std::future<void> barrier_future = barrier.get_future();
        std::thread new_work_thread(promise_thread_sync_flag, std::move(barrier));
        barrier_future.wait();
        cout << "thread has set value" << endl;
        new_work_thread.join();
    }


    static void promise_store_value(std::promise<int> &barrier)
    {
        try {
            // barrier.set_value(1); // set only once
            throw std::system_error(EACCES,std::generic_category(),"syserr");

        } catch (...) {
            barrier.set_exception(std::current_exception());
        }
    }

    void test_promise_exception()
    {
        std::promise<int> barrier;
        std::thread t1(promise_store_value, std::ref(barrier));
        std::cout << "waiting promise data...\n";
        //barrier_future.wait();
        std::future<int> barrier_future = barrier.get_future();

        try {
            std::cout << "result: " << barrier_future.get() << '\n';
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "caught some error " << endl;
        }

        t1.join();
    }

//    void test_promise2()
//    {
//        std::promise<int> barrier;
//        std::future<int> barrier_future = barrier.get_future();
//        auto result1 = std::async(std::launch::async, doPromiseWork, 10, std::move(barrier));
//        std::cout << "waiting promise data...\n";
//        barrier_future.wait();
//        std::cout << "result: " << barrier_future.get() << '\n';
//        //t1.join();  //如果t1处于joinable状态倍dtor,那么会调用terminate???
//    }





    // thread =================================
    void doSomething(int num,char c) {
        try {
            default_random_engine dre(42*c);
            uniform_int_distribution<int> id(10,10000);
            for (int i=0;i<num;i++) {
                this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
                cout.put(c).flush();
            }
        } catch (const exception &e ) {
            cerr << "THREAD-EXCEPTION (thread "
                 << this_thread::get_id() << "):" << e.what() <<endl;
        } catch (...) {
            cerr << "THREAD-EXCEPTION (thread "
                 << this_thread::get_id() << "):" <<endl;
        }
    }

    void testThread() {
        try {
            std::thread t1(doSomething, 5, '.');
            cout << "- started fg thread " << t1.get_id() << endl;
            cin.get();
            cout << "- join fg thread " << t1.get_id() << endl;
        } catch (const exception &e) {
            cerr << "EXCEPTION" << e.what() <<endl;
        }
    }



}

DEFINE_CODE_TEST(004_concurrency)
{
    //testMutex();
    /*
    recursiveLockError();
    recursiveLock();
    tryLock();
    lock2Items();
    uniqueLock();*/

    //test_promise_sync();
    //test_promise_exception();

    //testPromise();
    //test_promise2();
    // testThread();


    //test_future1();
    //test_future2();
    //test_future3();
    test_future4();
    cout << "return to outer" << endl;
    this_thread::sleep_for(chrono::seconds(30));

    //task_lambda();
}