#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>

#include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(const std::string& name);
    Peon(const Peon& other);
    Peon& operator=(const Peon& other);
    ~Peon();

    virtual void getPolymorphed() const;

private:
    Peon();
};

#endif /* PEON_HPP */
