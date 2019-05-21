//
// Created by rui.zhou on 3/21/2019.
//

#include <codech/codech_def.h>
#include <functional>
using namespace std;
//perfect forward failure case
namespace {
    // ---------------------------------------------
    // 参数为initializer_list的时候
    void f1(const vector<int>&v) {
        cout << v.size() << endl;
    }
    template<typename ...T>
    void fwd1(T&& ... param){
        f1(std::forward<T>(param)...);
    }

    void test_initializer_list() {
        //f1({1,2,3,4});  //good
        auto param = {1,2,3,4};
        cout << typeid(param).name() << endl;
        fwd1(param);
    }

    // ---------------------------------------------
    // 参数为static const data member
    void f2(std::size_t val) {
        cout << val << endl;
    }
    template<typename ...T>
    void fwd2(T&& ... param){
        f2(std::forward<T>(param)...);
    }

    class Widget {
    public:
        static const std::size_t MinVals = 28;
    };
    void test_static_member() {
        //fwd2(Widget::MinVals);
        //f2(Widget::MinVals);
    }

    // ---------------------------------------------
    //重载函数名字和模板名字
    void f(int (*pf)(int)) { }
    int processVal(int value) { return 0;}
    int processVal(int value, int priority) {return 0;}

    //void f(int pf(int)) {  }
    template<typename T>
    void fwd(T&& param)          // 接受参数
    {
        f(std::forward<T>(param));      // 转发到f
    }

    void testfuncptr()
    {
        f(processVal);  //f(int (*pf)(int))
        //fwd(processVal);  // 不知道匹配哪个
        using ProcessFuncType = int (*)(int);
        ProcessFuncType processValPtr = processVal;
        fwd(processValPtr);  // 指明类型
        //auto bindfunc = bind(processVal,placeholders::_1,placeholders::_1); // bind也不行，不知道bind哪个
        //fwd();
    }
}
DEFINE_CODE_TEST(emc_130_perfect_forward)
{
    //testfuncptr();
    //test_initializer_list();
    test_static_member();
}

