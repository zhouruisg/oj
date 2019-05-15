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
        D ddd;
    }


    // exception in dtor
    class ExceptionDtor  {
    public:
        ~ExceptionDtor() {
            throw 0;
        }
    };

    void exception_in_dtor()  {
        try {
            ExceptionDtor aa;
        } catch (int&) {
            std::cout << "catch int exception in dtor" << std::endl;  // can't catch exception in dtor
        } catch (...) {
            std::cout << "catch ... exception in dtor" << std::endl;  // // can't catch exception in dtor
        }
    }

    // E1 ctor抛异常，E2 dtor抛异常，先构造E2, 再构造E1,此时需要回收E2, 然而E2 在dtor中抛异常，导致直接terminate,即使外层包了
    // try-catch block也不行
    class E1 {
    public:
        E1()  {  std::cout<<"E1()"<<std::endl; throw "e1 exception"; }
        ~E1()  {  std::cout<<"~E1()"<<std::endl;  }
    };

    class E2{
    public:
        E2()  {  buf=malloc(100);  std::cout<<"E2 ctor()"<<std::endl;        }
        ~E2() {  std::cout<<"~E2()"<<std::endl; if (buf) free(buf); throw "E2";}//unable to handle this }
        void *buf;
    };

    class F  {
    public:
        F()
        try
        {
            std::cout<<"F()"<<std::endl;  // not reach here, in constructing sub obj(E1,E2...)
        }
        catch (...)
        {  std::cout<<"catch some exp"<<std::endl;
        }
        ~F() { std::cout<<"~F()"<<std::endl;    }

    private:
        E2 e2;
        E1 e1;
    };

    void test_execption_dtor2() {
        try {
            F obj;
        }
        catch (...)
        {
            std::cout<<"catch exp"<<std::endl;
        }
    }
}

DEFINE_CODE_TEST(007_exception)
{
//    vector_resize_test();
//    partial_ctor();
    //test_function_try_block();
    //exception_in_dtor();
    test_execption_dtor2();
}

