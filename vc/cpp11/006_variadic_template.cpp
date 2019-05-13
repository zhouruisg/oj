//
// Created by rui zhou on 13/05/19.
//

//可变模版参数
#include <codech/codech_def.h>
using namespace std;

namespace {
    template<typename Func, typename ... Args>
    auto curry(Func func, Args...args) {
        return [=](auto ...lastParam) {
            //cout << "bind " << lastParam << endl;
            return func(args...,lastParam...); // args 先绑定了第一次预设的参数，然后返回的这个lambda还可以再接受一个参数
        };
    };

    int areaOfRectangle(int length, int width) {
        return length*width;
    }

    void test_curry() {
        int test_a;
        auto comp = [&]() {
            cout <<test_a<<endl;
        };

        auto findMax= [](auto &x,auto &y) {
            return x>y?x:y;
        };
        auto length5 = curry(areaOfRectangle, 5);  //类似bind的作用
        for (int i=0;i<=5;i++) {
            cout << "length5("<<i<<") =" << length5(i) << endl;
        }
    }


    template <typename T, typename...Args>
    void print(const T& firstArg, const Args& ...args) {// 用于萃取第一个参数出来
        cout << firstArg << endl;
        print(args);
    };

    void test_print() {
        print(7.5, "hello", std::bitset<16>(377), 42);
    }

}


DEFINE_CODE_TEST(006_variadic_template)
{
    test_curry();
    test_print();
}
