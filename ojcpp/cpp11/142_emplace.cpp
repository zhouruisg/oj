//
// Created by rui zhou on 12/02/19.
//

#include <codech/codech_def.h>
using namespace std;

namespace emc {
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
    };

    void copyctor() {
        vector<A> vec;
        A a;
        vec.push_back(a);
    }

}

DEFINE_CODE_TEST(emc_142_emplace)
{
    emc::copyctor();
}