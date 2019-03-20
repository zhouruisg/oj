//
// Created by rui.zhou on 3/20/2019.
//
#include <codech/codech_def.h>
using namespace std;
namespace {
    class Person {
    public:
//        template<typename T,
//                typename = typename std::enable_if<
//                        !std::is_same<Person,typename std::decay<T>::type>::value
//                >::type
//        >
//        explicit Person(T&& n) {
//            cout << "ctor uniref" << endl;
//        }

        //通过这个样式，让派生类避免调用这个universal reference 的重载
        template<typename T,
                typename = std::enable_if_t<
                        !std::is_base_of<Person,typename std::decay_t<T>>::value
                >
        >
        explicit Person(T&& n) {
            cout << "ctor uniref" << endl;
        }

        Person(const Person &rhs) {
            cout << "copy ctor" << endl;
        }
        Person(){cout <<"default ctor"<<endl;}
    };
    void testEnableIf() {
        Person p("nancy");
        Person p1(p);  //won't call
    }

    // test derived class
    class SpecialPerson : public Person {
    public:
        SpecialPerson(const SpecialPerson&rhs)
        :Person(rhs){
        }
        SpecialPerson() {

        }
    };

//    class SpecialPerson1 {
//    public:
//        SpecialPerson1(const SpecialPerson1&rhs) {
//
//        } //一旦声明了copy ctor,就不会自动生成default ctor
//    };

    void testChild() {
        SpecialPerson p1; // no default ctor because has copy ctor
        SpecialPerson p2(p1);
    }

}

DEFINE_CODE_TEST(127_overload_uniref)
{
    //testEnableIf();
    testChild();
}