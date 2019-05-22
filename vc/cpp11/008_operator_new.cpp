//
// Created by rui.zhou on 5/17/2019.
//

#include <codech/codech_def.h>
using namespace std;
namespace {
    // 一个基本的operator new 例子
    class A    {
    public:
        A() {
            std::cout<<"call A constructor"<<std::endl;
        }

        ~A() {
            std::cout<<"call A destructor"<<std::endl;
        }
        void* operator new(size_t size) {
            std::cout<<"call A::operator new, size="<< size << std::endl;
            return malloc(size);
        }

        void* operator new(size_t size, const std::nothrow_t& nothrow_value)  {
            std::cout<<"call A::operator new nothrow"<<std::endl;
            return malloc(size);
        }
    };

    void test_operator_new() {
        A* p1 = new A;
        cout << p1 << endl;
        delete p1;

        A* p2 = new(std::nothrow) A;
        cout << p2 << endl;
        delete p2;
    }

    // EFC 049 ---------------------------------------------------
    // 使用CRTP curiously recursive template
    template<typename T> // “mixin-style” base class for
    class NewHandlerSupport { // class-specific set_new_handler
    public: // support
        static std::new_handler set_new_handler(std::new_handler p) throw() {
            std::new_handler oldHandler = currentHandler;
            currentHandler = p;
            return oldHandler;
        }

        static void* operator new(std::size_t size) throw(std::bad_alloc) {
            size = size * 1000;
            cout << "operator new size=" << size << endl;
            for (;;) {
                if (void *p=malloc(size)) return p;
                new_handler globalHandler = set_new_handler(0);
                set_new_handler(globalHandler);
                if (globalHandler)
                    (*globalHandler)();
                else
                    throw std::bad_alloc();
            }
            std::new_handler h = std::set_new_handler(currentHandler);
            //return ::operator new(size);
        }
        // other versions of op. new —
        // see Item 52
    private:
        static std::new_handler currentHandler;
    };

    // this initializes each currentHandler to null
    template<typename T>
    std::new_handler NewHandlerSupport<T>::currentHandler = 0;

    class B :public NewHandlerSupport<B> {
    public:
        B() {
            cout << "B ctor" << endl;
        }
    private:
        //int buf[1000*1000*1000]; // 1G -> vc error
		int buf[1000 * 1000]; //  
    };

    void test_crtp() {
        // 并不能捕捉exception
        // 直接声明对象的方法也不会去call operator new
//        try {
//            B objb1;
//        } catch (...) {
//            cout << "caught error objb" << endl;
//        }

        B *objb = nullptr;
        try {
            objb = new B();
        } catch (...) {
            cout << "caught error objb=" << objb << endl;
        }
    }
}

DEFINE_CODE_TEST(008_operator_new)
{
    //test_operator_new();
    test_crtp();
}