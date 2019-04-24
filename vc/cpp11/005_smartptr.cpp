//
// Created by rui zhou on 24/04/19.
//

#include <codech/codech_def.h>
using namespace std;

namespace autoptr {
    struct Resource
    {
        Resource()
        {
            x = 101;
            std::cout << "ctor" << std::endl;
        }
        ~Resource()
        {
            x = 0;
            std::cout << "dtor" << std::endl;
        }
        int x;
    };

    void auto_ptr_test()
    {
        {
            auto_ptr<Resource> pt(new Resource);
        }
        vector<auto_ptr<Resource>> vec;
        vec.push_back(auto_ptr<Resource>(new Resource()));

        {
            auto_ptr<Resource> pt1 = vec[0];  // ownership transfer to pt1
            std::cout << pt1->x << std::endl;
        }

        std::cout << vec.size() << vec[0]->x <<std::endl;
    }
}

namespace {
    struct B {
        virtual void bar() { std::cout << "B::bar\n"; }
        virtual ~B() = default;
    };
    struct D : B
    {
        D() { std::cout << "D::D\n"; }
        ~D() { std::cout << "D::~D\n"; }
        void bar() override { std::cout << "D::bar\n"; }
    };

    auto deleter = [](D* ptr) {
        cout << "I am deleter" << endl;
        if (ptr)
            delete ptr;
    };

    auto deleter2 = [](D obj) {
        cout << "I am deleter2" << endl;
        //if (ptr)
        //    delete ptr;
    };

    void unique_ptr_test()
    {
        {
            auto p1 = std::make_unique<D>(); // p is a unique_ptr that owns a D
            //auto invalid = p1;  // no copy ctor in unique_ptr
            // same size as plain struct
            cout << "unique ptr size is " << sizeof(p1) << " struct B size is " << sizeof(B) << endl;
            auto p2 = std::unique_ptr<D>(new D());

            // transfer ownership
            std::unique_ptr<D> p3(std::move(p2));  // p2
            if (!p2) {
                cout << "p2 is no more valid" << endl;
            }

            //auto q = pass_through(std::move(p));
            //assert(!p); // now p owns nothing and holds a null pointer
            // q->bar();   // and q owns the D object
        } // ~D called here

        {
            std::unique_ptr<D,decltype(deleter)> p4(nullptr,deleter);
            std::unique_ptr<D> p5;
            std::unique_ptr<D,decltype(deleter)> p6(new D(),deleter); // call I m deleter
            cout << "unique ptr with deleter size " << sizeof(p6) << endl;
            // std::unique_ptr<D,decltype(deleter)> p6; not compiled
        } // for not null ptr call deleter here

        {
            std::unique_ptr<D,decltype(deleter2)> p6(new D(),deleter2   ); // call I m deleter
        }
    }
}

namespace weakptr{
    // weak_ptr -------------------------------------------
    struct Resource
    {
        Resource()
        {
            x = 101; // 4bytes
            std::cout << "ctor" << std::endl;
        }
        ~Resource()
        {
            x = 0;
            std::cout << "dtor" << std::endl;
        }
        int x;
    };

    void weak_ptr_test()
    {
        cout << "// weak_ptr -------------------------------------------" << endl;
        std::shared_ptr<Resource> p1 = std::make_shared<Resource>();
        std::cout << "size of shared ptr " << sizeof(p1) << std::endl;  // 8bytes, 4-raw ptr, 4-count block?

        std::weak_ptr<Resource> wp1(p1);
        std::cout << "use count : " << wp1.use_count() << "\n";
        p1.reset();

        //weak ptr->shared ptr
        std::shared_ptr<Resource> spw1 = wp1.lock();
        if (spw1)
        {
            std::cout << "create a shared ptr from the resource" << std::endl;
            std::cout << "use count after a new shared_ptr: " << wp1.use_count() << "\n";
        }
        // std::shared_ptr<Resource> spw2 = wpw1;  // compiler error
        p1.reset();
        p1 = nullptr;
        std::cout << "use count after spw reset: " << wp1.use_count() << "\n";

        if (wp1.expired())
        {
            std::cout << "the object was destroy" << std::endl;
        }
    }
}

DEFINE_CODE_TEST(005_smartptr)
{
    unique_ptr_test();
    weakptr::weak_ptr_test();
}

