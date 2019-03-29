//
// Created by rui.zhou on 3/21/2019.
//

#include <codech/codech_def.h>
#include <functional>
using namespace std;

namespace {
    void f(int (*pf)(int)) {

    }
    //void f(int pf(int)) {  }
    template<typename T>
    void fwd(T&& param)          // 接受参数
    {
        f(std::forward<T>(param));      // 转发到f
    }
    int processVal(int value) { return 0;}
    int processVal(int value, int priority) {return 0;}

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
    testfuncptr();
}

