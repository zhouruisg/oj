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
    // Atomic
    // promise =================================
    static int fib(int n)
    {
        if (n < 3) return 1;
        else return fib(n - 1) + fib(n - 2);
    }
    static void doPromiseWork(int n, std::promise<int> barrier)
    {
        int result = fib(n);
        barrier.set_value(result);  //promise提供一个值
    }

    void testPromise()
    {
        std::promise<int> barrier;
        std::future<int> barrier_future = barrier.get_future();
        std::thread t1(doPromiseWork, 10, std::move(barrier));  //状态shared_state转移到函数内的变量
        //也可以使用std::ref(barrier)
        std::cout << "waiting promise data...\n";
        barrier_future.wait();
        std::cout << "result: " << barrier_future.get() << '\n';
        t1.join();  //如果t1处于joinable状态倍dtor,那么会调用terminate
    }
    // future =================================


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

DEFINE_CODE_TEST(004_lock)
{
    //testMutex();
    /*
    recursiveLockError();
    recursiveLock();
    tryLock();
    lock2Items();
    uniqueLock();*/
    testPromise();
    // testThread();
}