#include "TestDerived.hpp"

#include <iostream>

TestDerived::TestDerived(const std::string& name) : Victim(name) {
    std::cout << "TestDerived Zog zog." << std::endl;
}

TestDerived::TestDerived(const TestDerived& other) : Victim(other) {}

TestDerived& TestDerived::operator=(const TestDerived& other) {
    if (this != &other) {
        Victim::operator=(other);
    }
    return *this;
}

TestDerived::~TestDerived() {
    std::cout << "TestDerived Bleuark..." << std::endl;
}

void TestDerived::getPolymorphed() const {
    std::cout << getName() << " has been turned into a purple pony!"
              << std::endl;
}
