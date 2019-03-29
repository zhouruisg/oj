//
// Created by rui.zhou on 3/21/2019.
//

#include <codech/codech_def.h>
#include <array>
using namespace std;
namespace {
    void array2D() {
        std::array<std::array<int, 3>, 3> arr = {{{5, 8, 2}, {8, 3, 1}, {5, 3, 9}}};
    }
    void testArray() {
        std::array<int,5> a{1,2,3,4,5};
        std::array<int,5> b(move(a));
    }
}

DEFINE_CODE_TEST(emc_129_move)
{
    testArray();
}