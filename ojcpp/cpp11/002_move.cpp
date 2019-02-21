//
// Created by rui zhou on 21/02/19.
//

#include <codech/codech_def.h>
using namespace std;
namespace c11
{
    // 参考string move ctor实现
    void test_string() {
        string s(std::move(string("aaa")));
        cout <<s<<endl;
    }
    struct A
    {
        std::string s;
        A() : s("test")
        {
            std::cout << "A ctor\n";
        }
        A(const A& o) : s(o.s)
        {
            std::cout << "A copy ctor\n";
        }
        A(A&& o) noexcept : s(std::move(o.s))
        {
            std::cout << "A move ctor,skip memory copy,just swap ptr\n";
        }
    };

    void test_vector_push_back_rvalue() {
        vector<A> vec{A(),A(),A()};
        //vec.push_back(A());  //move ctor
        cout<<"=========================================\n";
        A alv;
        vec.push_back(alv);  //copy ctor
    }


}


DEFINE_CODE_TEST(c11_002_move)
{
    //c11::test_string();
    c11::test_vector_push_back_rvalue();
}
