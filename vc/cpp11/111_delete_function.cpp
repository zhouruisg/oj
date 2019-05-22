//
// Created by rui.zhou on 5/22/2019.
//
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Widget {
    public:
        template<typename T>
        void processPointer(T* ptr){ }
//        template<>
//        void processPointer<void>(void*) = delete; // not allow inside class
    };

//    template<>
//    void Widget::processPointer<void>(void*) = delete; // outside class is good

    void test_delete_template() {
        Widget obj;
        int x=1;obj.processPointer(&x); //good
        //obj.processPointer(); // bad
    }
}

DEFINE_CODE_TEST(111_delete_function)
{
    test_delete_template();
}