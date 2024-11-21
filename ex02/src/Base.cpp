
#include "../includes/Base.hpp"

Base::~Base(void) {}

A::A(void) {}

A::~A(void) {}

B::B(void) {}

B::~B(void) {}

C::C(void) {}

C::~C(void) {}

Base* generate(void) {
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();
    int i = std::rand()%3;

    switch (i)
    {
    case 0:
        delete b;
        delete c;
        return a;
    case 1:
        delete a;
        delete c;
        return b;
    case 2:
        delete a;
        delete b;
        return c;
    default:
        delete a;
        delete b;
        delete c;
        std::cerr << "Unexpected error\n";
        break;
    }
    return NULL;
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p))
       std::cout << "Object pointer is an A type\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Object pointer is a B type\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Object pointer is a C type\n";
    else 
        std::cout << "Unknown type\n";
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Object reference is an A type\n";
        return ;
    }
    catch (std::exception& e) {}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Object reference is an B type\n";
        return ;
    }
    catch (std::exception& e) {}
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Object reference is an C type\n";
        return ;
    }
    catch (std::exception& e) {}
        std::cout << "Unexpected error\n";
    return ;
}