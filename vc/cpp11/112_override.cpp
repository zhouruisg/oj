//
// Created by rui.zhou on 5/22/2019.
//
#include <codech/codech_def.h>
using namespace std;
namespace {
    class Base {
    public:
        virtual void mf1() const{ cout << "Base" << endl; };
        virtual void mf1(int x) {cout << "Base" << endl;}
        virtual void mf2(int x){};
        virtual void mf3() &{};
        void mf4() const{};
    };
    class Derived: public Base {
    public:
        virtual void mf1()  {
            cout << "Derived" << endl;
        };
        virtual void mf2(unsigned int x){};
        virtual void mf3() &&{};
        void mf4() const{};
    };
    void test_noorverride() {
        Base *dobj1 = new Derived();
        dobj1->mf1(); // ->base
        Derived *dobj2 = new Derived();
        dobj2->mf1(); // ->derived
        // dobj2->mf1(5); // error // no matching call
    }
}

namespace override {
//    class Base {
//    public:
//        virtual void mf1() const{ cout << "Base" << endl; };
//        virtual void mf1(int x) {cout << "Base" << endl;}
//        virtual void mf2(int x){};
//        virtual void mf3() &{};
//        void mf4() const{};
//    };
//    class Derived: public Base {
//    public:
//        //marked derived override , but does not override
//        virtual void mf1() override { cout << "Derived" << endl; };
//        virtual void mf2(unsigned int x) override{};
//        virtual void mf3() && override{};
//        void mf4()  const override{};
//    };
}
DEFINE_CODE_TEST(112_override)
{
    test_noorverride();
}