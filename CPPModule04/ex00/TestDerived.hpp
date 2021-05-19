#ifndef TESTDERIVED_HPP
#define TESTDERIVED_HPP

#include "Victim.hpp"

class TestDerived: public Victim {
public:
    TestDerived(const std::string& name);
    TestDerived(const TestDerived& other);
    TestDerived& operator=(const TestDerived& other);
    ~TestDerived();

    virtual void getPolymorphed() const;

private:
    TestDerived();

};

#endif /* TESTDERIVED_HPP */
