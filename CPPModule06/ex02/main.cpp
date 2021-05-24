#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


void identify_from_pointer(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    } catch (const std::bad_cast& e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    } catch (const std::bad_cast& e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    } catch (const std::bad_cast& e) {}
}

Base* generate() {
    switch (std::rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

int main() {
    Base base;
    A a;
    B b;
    C c;

    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        std::cout << "TEST " << i << std::endl;
        Base *unknown = generate();
        std::cout << "identify_from_pointer: ";
        identify_from_pointer(unknown);
        std::cout << "identify_from_reference: ";
        identify_from_reference(*unknown);
        delete unknown;
    }

    return 0;
}
