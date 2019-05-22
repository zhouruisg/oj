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
    //array size
//    template<typename T, std::size_t Size>
//    std::size_t GetArrLength(T(&)[Size]) { return Size; }

    template<typename T, std::size_t Size>
    constexpr std::size_t GetArrLength(T(&)[Size]) { return Size; }

    void test_arraysize() {
        int a[100];
        cout << GetArrLength(a) << endl;
        for (int i=0;i<GetArrLength(a);i++) {

        }
    }

    // cpu size
//    template<int>
//    constexpr auto MyPlatform();
//
//    template<>
//    constexpr auto MyPlatform(4)
//    {
//        return 32;
//    }
//
//    template<>
//    auto MyPlatform<8>()
//    {
//        return 64;
//    }

    template<std::size_t n>
    constexpr int Am_I_bit(){
        return (sizeof(void*)*CHAR_BIT)==n;
    }

    constexpr int platform_32(){
        return Am_I_bit<32>();
    }

    constexpr int platform_64(){
        return Am_I_bit<64>();
    }

    void test_platform() {
        if (platform_32()) {
            cout <<"32 bit platform" << endl;
        } else if (platform_64()) {
            cout <<"64 bit platform" << endl;
        }
    }// helper function just to hide clumsy syntax



}

DEFINE_CODE_TEST(009_metaprogramming)
{
    //test_checkingtype();
    test_arraysize();
    test_platform();
}