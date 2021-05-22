#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>

#include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(const std::string& name);
    virtual ~Peon();

    Peon(const Peon& other);
    Peon& operator=(const Peon& other);

    virtual void getPolymorphed() const;

private:
    Peon();
};

std::ostream& operator<<(std::ostream& stream, const Peon& peon);

#endif /* PEON_HPP */
