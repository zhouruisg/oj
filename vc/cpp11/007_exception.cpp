//
// Created by rui.zhou on 5/15/2019.
//
#include <codech/codech_def.h>
using namespace std;

namespace {
    // 一个每当构造超过10次就会抛异常的类
    struct A   {
        A()  {
            static int count = 0;
            if (count > 10) {
                throw 1;
            }
            std::cout << "ctor " << count++ << std::endl;
        }
        ~A() {
            static int count = 0;
            std::cout << "dtor " << count++ << std::endl;
        }
    };

    void vector_resize_test()
    {
        {
            std::vector<A> vec;
            vec.resize(20); //由于vector.resize()内部有try-catch机制，在ctor抛出异常的时候，能把前面已经构造的object 释放掉
        }
    }

    // 在部分构造失败的时候，如果外部没有try-catch  block, 无法对已构造的子对象执行dtor.
    // 针对的是子对象，如果是通过 ptr = new A()之类的方式创建的，那么dtor 是施加在ptr 这种built-in类型上，等同于对int 对象执行dtor(没有效果)
    class B {
    public:
//        B() {
//            for (int i=0;i<20;i++) {
//                ptrs[i]=new A();  // 通过new方式的不会在失败时call dtor 释放资源(ptr built-in type)
//            }
//        }
//        A* ptrs[10];
        A objs[20];
    };

    void partial_ctor() {
        //B objb;  // 在构造第10个A对象后失败，抛出异常，但此时并没有call A dtor,因为没有 try-catch block?
        try {
            B objb;
        } catch (int& err) {
            cout << "catch error " << err << endl;  //正常捕捉
        }
    }

    // -------------------------------------------------
    //TODO function try block 还不是很明白机制
    // --absorb exception inside ctor -----------------
    struct C {
        C(){
            try {
                throw "1";
            } catch (...) {
                std::cout << "catch something wrong\n";
            }
        }
        ~C()    {}
    };

    struct D {
        D()
        try :x(5){
            throw "1";
        } catch (...) {
            std::cout << "catch something wrong in function try block\n";
        }
        ~D() {}
        int x;
    };
    void test_function_try_block() {
        C objc;
        D objd;  /// call abort, must throw outside function block
    }


    //---------------------------------------------------
    // 析构函数中抛出异常，exception in dtor, 不允许，调用terminate 结束
//    class ExceptionDtor  {
//    public:
//        ~ExceptionDtor() {
//            throw 0;
//        }
//    };
//
//    void exception_in_dtor()  {
//        try {
//            ExceptionDtor aa;
//        } catch (int&) {
//            std::cout << "catch int exception in dtor" << std::endl;  // can't catch exception in dtor
//        } catch (...) {
//            std::cout << "catch ... exception in dtor" << std::endl;  // // can't catch exception in dtor
//        }
//    }

    // E1 ctor抛异常，E2 dtor抛异常，先构造E2, 再构造E1,此时需要回收E2, 然而E2 在dtor中抛异常，导致直接terminate,即使外层包了
    // try-catch block也不行
//    class E1 {
//    public:
//        E1()  {  std::cout<<"E1()"<<std::endl; throw "e1 exception"; }
//        ~E1()  {  std::cout<<"~E1()"<<std::endl;  }
//    };
//
//    class E2{
//    public:
//        E2()  {  buf=malloc(100);  std::cout<<"E2 ctor()"<<std::endl;        }
//        ~E2() {  std::cout<<"~E2()"<<std::endl; if (buf) free(buf); throw "E2";}//unable to handle this }
//        void *buf;
//    };
//
//    class F  {
//    public:
//        F()
//        try
//        {
//            std::cout<<"F()"<<std::endl;  // not reach here, in constructing sub obj(E1,E2...)
//        }
//        catch (...)
//        {  std::cout<<"catch some exp"<<std::endl;
//        }
//        ~F() { std::cout<<"~F()"<<std::endl;    }
//
//    private:
//        E2 e2;
//        E1 e1;
//    };
//
//    void test_execption_dtor2() {
//        try {
//            F obj;
//        }
//        catch (...)
//        {
//            std::cout<<"catch exp"<<std::endl;
//        }
//    }
    // ----------------------------------------------------------------
    // 自定义异常 example
    #include <stdexcept>
    class MyException : public std::runtime_error {
    public:
        MyException() : std::runtime_error("MyException") { }
    };

    void do_some_work() {
        // ...
        throw MyException();
    }

    void test_use_exception()
    {
        try {
            do_some_work();
        } catch (std::exception &e) {
            cout << e.what() << endl;
        }
    }

    // ----------------------------------------------------------------
    // 异常规范
//    // 声明和定义的一场规范不一致，直接报告compiler error
//    void f() throw (std::bad_alloc);
//    void f() { // can throw anything
//        int x=5;
//    }

//   C++98
//   直接违反异常规范,没有编译器告警
//   try-catch block 无法捕捉
    void foo98() throw() {
        throw "foo 98";  // no compiler warning
    }

    // disable in C++14
    void foo98_throw() throw(int) {
        throw "foo 98";
    }

    void foo98_specok() throw(int) {
        throw 95;
    }

    void test_foo98() {
        try {
            //foo98();
            foo98_throw();
            //foo98_specok();
        } catch (...) {
            cout << "caught some error" << endl;
        }
    }


// 间接违反98异常规范
//    void foo98_indirect_throw() throw() {
//        foo98();
//    }

// C++11
// 无论 有无 try-catch都无法捕捉违反noexcept规范的，
// 给出 compiler warning
// 运行时abort
//    void foo11() noexcept // the function f() does not throw
//    {
//        throw "foo 11";
//    }
//
//    void test_foo11() {
//        //foo11();
//        try {
//            foo11();
//        } catch (...) {
//            cout << "caught something" << endl;
//        }
//    }

    void foo11_throw()
    {
        throw "foo 11";
    }
    void foo11_indriect() noexcept // the function f() does not throw
    {
        foo11_throw();
//        try {
//            foo11_throw();
//        } catch (...) {
//            cout << "caught something" << endl;
//        }
    }

    // 无compiler warning
    // 无法捕捉，因为foo11_indirect 规范为 noexcept,所以最后会abort
    // 如果把try-catch 放到foo11_indirect的话，就没有问题，
    // 因为异常没有出foo11_indirect
    void test_foo11_indirect() {
        try {
            foo11_indriect();
        } catch (...) {
            cout << "caught something" << endl;
        }
    }

    void test_execption_spec() {
        //test_foo11_indirect();
        //test_foo98();
    }

    // ---------------------------------------------------
    // 当抛出了一个不在异常规范(dynamic-exception-specification)中的异常时，unexpected handler会被调用。
    // 如果符合异常规范，那么继续走其它途径，例如判断是否uncaught exception
    void myunexpected () {
        std::cerr << "unexpected called\n";
        throw 0;     // throws int (in exception-specification)
    }

    void myfunction () throw (int) {
        throw 'x';   // throws char (not in exception-specification)
    }

    void myfunction2() {
        throw 'y';
    }
    int test_unexpected_handler (void) {
        std::set_unexpected (myunexpected);
        try {
            myfunction();  // 违反异常规范，在unexpected_handler中重新抛出符合要求的
            //从而在catch (int)中被捕捉
        }
        catch (int) { std::cerr << "caught int\n"; }
        catch (...) { std::cerr << "caught some other exception type\n"; }

        cout << "-----------------------------------" << endl;
        try {
            myfunction2();  // 没有违反异常规范，但是不在catch 列表里，属于uncaught exception
        }
        catch (int) { std::cerr << "caught int\n"; }
		return 0;
    }

    // ---------------------------------------------
    // 处理 uncaught exception, 也可以显式用来中断程序运行,abort或者exit
    void test_terminate_handler()
    {
        std::set_terminate([]() {
            std::cout << "this is terminate handler\n";
            //return;  // 仍然是abort
            //exit(1);  // normal exit
           std::abort();  //仍然是abort, 但是vc可能显示abort message on windows
        });
        //test_foo98(); // uncaught exception
        std::terminate();  //显式调用
    }

    // ---------------------------------------------
    // 利用RAII来构建exception-safe的对象
    // 使用智能指针来管理每个子对象，这样发生异常的时候，能保证对已构造的子对象执行dtor
    class G  {
    public:
        G() {
            buf=malloc(100);
            throw "G exception";
        }
        ~G() {
            if (buf) free(buf);
        }
    private:
        void *buf;
    };

    class G2 {
    public:
        G2():buf(new char[100]) {
            for (int i=0;i<100;i++) {
                buf[i]= '0'+i;
            }
            for (int i=0;i<100;i++) {
                cout << buf[i] << " ";
            }
            cout << endl;
        }
        ~G2() {
            cout << "G2 dtor" << endl;
        }
        std::unique_ptr<char[]> buf;
    };

    class G1  {
    public:
        G1():buf(new G2) {
            throw "G1 exception";
        }
        ~G1() {
            cout << "G1 dtor" << endl;
        }
    private:
        std::unique_ptr<G2> buf;
    };

    void test_raii_object() {
        try{
            //G objg;
            G1 objg1;
        }
        catch(...) {
            cout << "caught some error" << endl;
        }
    }




}

DEFINE_CODE_TEST(007_exception)
{
//    vector_resize_test();
//    partial_ctor();
    //test_function_try_block();
    //exception_in_dtor();
    //test_execption_dtor2();
    //test_use_exception();

    //异常规范
    //test_execption_spec();

    //test_unexpected_handler();
    //test_terminate_handler();
    test_raii_object();

}

