//
// Created by rui.zhou on 3/20/2019.
//

// move 只用在 rvalue, forward只用在universal reference
#include <codech/codech_def.h>
//#include <utility>
using namespace std;

namespace {
    class Widget {
    public:
        Widget() {cout <<"widget ctor" <<endl;}
        // 导致lvalue 的值被move
        template<typename T>
        void setName(T&& newName) {
            name= std::move(newName);
            cout << "widget name=" << name <<endl;
        }
        void print() {cout << name <<endl;}
    private:
        string name;
    };

    void testMove() {
        Widget w;
        w.setName("string literal"); // no temporary string created, T is const char[15]
        string localVar="local_var";
        cout << "local var before" << localVar <<endl;
        w.setName(localVar);
        cout << "local var after" << localVar<<endl;
    }

    // use over load P171
    // fixed
    class Widget1 {
    public:
        template<typename T>
        void setName(T&& newName) {
            name= std::forward<T>(newName);
            cout << "widget name=" << name <<endl;
        }
    private:
        string name;
    };

    void testForward() {
        Widget1 w;
        w.setName("string literal"); // no temporary string created, T is const char[15]
        string localVar="local_var";
        cout << "local var before " << localVar <<endl;
        w.setName(localVar);
        cout << "local var after " << localVar<<endl;
    }

    //RVO
    Widget makeWidget() {
        Widget w;
        w.setName("I am created in function");
        return std::move(w);
    }

    void testMakeWidget() {
        Widget w = makeWidget();
        w.print();
        //makeWidget().print();
    }

}


DEFINE_CODE_TEST(125_forward_with_uniref)
{
    //testForward();
    testMakeWidget();
}
