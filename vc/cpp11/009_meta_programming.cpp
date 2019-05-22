//
// Created by rui.zhou on 5/22/2019.
//
#include <codech/codech_def.h>
using namespace std;

namespace {
    // template specialization
    template<typename A,typename B>
    struct CheckingType {
        enum {
            result = 0
        };
    };
    template<typename X>
    struct CheckingType<X,X> {
        enum {
            result = 1
        };
    };

    //编译时类型判断
    void test_checkingtype() {
        int a=1;
        float b=0.1;
        if (CheckingType<float,int>::result==1) {  // not CheckingType<a,b> ...
            cout << "same type" << endl;
        }
    }
}

DEFINE_CODE_TEST(009_metaprogramming)
{
    test_checkingtype();
}