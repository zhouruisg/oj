//
// Created by rui.zhou on 3/20/2019.
//
#include <codech/codech_def.h>
using namespace std;
namespace {
    class Person {
    public:
        template<typename T,
                    typename = typename std::enable_if<
                            !std::is_same<Person,typename std::decay<T>::type>::value
                            >::type
                >
        explicit Person(T&& n) {
            cout << "ctor" << endl;
        }
    };
    void testEnableIf() {
        Person p("nancy");
        Person p1(p);  //won't call
    }
}

DEFINE_CODE_TEST(127_overload_uniref)
{
    testEnableIf();
}