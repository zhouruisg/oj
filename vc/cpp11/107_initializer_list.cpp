//
// Created by rui zhou on 21/05/19.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Widget {
    public:
        Widget() {
            std::atomic<int> m_ai2(0);
        }
        Widget(int i, bool b) {
            std::cout << "Widget(int i, bool b)" << std::endl;
        }
        Widget(int i, double b) {
            std::cout << "Widget(int i, double b)" << std::endl;
        }
        Widget(std::initializer_list<long double> il) {
            std::cout << "Widget(std::initializer_list<long double> il)" << std::endl;
        }

        std::vector<int> m_vec{ 0,1,2,3,4 };
        int x{ 20 };
        std::atomic<int> m_ai1{ 0 };  // no assignment
        // std::vector<int> m_vec2{ 1.0,2,3 };   error
    };

    void test_initializer_list() {
        Widget w1(10,true);
        Widget w2{10, true};   // => Widget(initializer_list)
        Widget w3{ 10, 5.0};
        Widget w4{ 10.0, 5.0 };
    }
}

DEFINE_CODE_TEST(107_initializer_list)
{
    test_initializer_list();
}
