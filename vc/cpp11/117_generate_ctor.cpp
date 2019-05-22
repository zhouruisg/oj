//
// Created by rui.zhou on 5/22/2019.
//
#include <codech/codech_def.h>
using namespace std;

namespace rvo {
    class Widget {
    public:
        ~Widget(){}
        Widget(){ cout << "default ctor"<<endl;}
        Widget(int x){ cout << "ctor with int"<<endl;}
        Widget(const Widget&rhs) {
            cout << "copy ctor"<<endl;
        }
        Widget(Widget&rhs) {
            cout << "non-const copy ctor"<<endl;
        }
        Widget(Widget&&rhs) {
            cout << "move ctor"<<endl;
        }
    };

    Widget f() {
        Widget obj(5);
        return obj;
    }

    Widget g(Widget w) {
        return w;
    }
    void test_generate_ctor() {
        Widget obj1(f()); // only call ctor(int) once
        cout << "====================\n";
        Widget obj2(move(f())); // call ctor(int) + move ctor
        cout << "====================\n";
        Widget obj3(g(Widget())); // call default  + move ctor
    }
}

namespace emc17 {
    struct Widget1 {
        Widget1(const Widget1&rhs) {}
    };
    void test_no_default_ctor() {
        //Widget1 obj;// error no default ctor because copy ctor
    }

    struct Widget2 {
        Widget2(){}
        Widget2& operator=(Widget2&&rhs) {} // move assignment
        //Widget2(Widget2&&rhs) {} // move ctor
    };
    void test_no_move_ctor() {
        Widget2 obj1;
        //Widget2 obj2(move(obj1));  // error no move ctor
    }

    struct Widget3 {
        Widget3(){}
        // if no copy ctor will generate trivial copy ctor
        //Widget3(const Widget3&rhs) {cout <<"copy ctor"<<endl;} //copy ctor
        //Widget3(Widget3&&rhs) {cout <<"move ctor"<<endl;} // move ctor
    };
    void test_no_move_ctor2() {
        Widget3 obj1;
        Widget3 obj2(move(obj1));  //no error, convert to copy ctor (expect move ctor)
    }

    struct Widget4 {
        Widget4& operator=(Widget4&rhs){} // no copy ctor?still have
    };
    void test_widget4() {
        Widget4 obj1;
        Widget4 obj2(obj1);
    }
}
namespace {
    class Widget {
    public:
        ~Widget(){}
        Widget(){ cout << "default ctor"<<endl;}
//        Widget(const Widget&rhs) {
//            cout << "copy ctor"<<endl;
//        }
//        Widget(Widget&rhs) {
//            cout << "non-const copy ctor"<<endl;
//        }
        Widget(Widget&&rhs) {
            cout << "move ctor"<<endl;
        }
    };
    Widget getWidget(Widget obj) {
        return obj;
    }
    Widget f() {
        Widget obj;
        return obj;
    }
    void test_generate_ctor() {
        Widget obj1;
//        Widget obj2 = obj1;  //copy ctor
//        obj1 = obj2;  // copy assignment
        //Widget obj3(Widget());  // move ctor
        //Widget obj4(getWidget(obj1));
//        cout << typeid(Widget()).name() << endl;
//        cout << typeid(obj1).name() << endl;
//        Widget obj4(Widget());

        Widget obj4 = f();
        //Widget obj5 = move(Widget());

    }
    class I20 {
    public:
        I20() {
            std::cout << "I20 ctor" << std::endl;
        }
        I20(I20 &&rhs) noexcept{
            std::cout << "I20 move ctor" << std::endl;
        }
        I20 operator *(const I20&rhs ) {
            I20 i;
            return i;
        }
    };

    void i20() {
        I20 i1,i2;
        I20 i3 = i1*i2; // 只有一次ctor
    }
}

DEFINE_CODE_TEST(117_generate_ctor)
{
    // rvo::test_generate_ctor();
    //emc17::test_no_default_ctor();
    //emc17::test_no_move_ctor();
    //emc17::test_no_move_ctor2();
    emc17::test_widget4();
    //i20();
}