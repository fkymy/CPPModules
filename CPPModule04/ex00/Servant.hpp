#ifndef SERVANT_HPP
#define SERVANT_HPP

#include <iostream>

#include "Victim.hpp"

class Servant: public Victim {
public:
    Servant(const std::string& name);
    ~Servant();

    Servant(const Servant& other);
    Servant& operator=(const Servant& other);

    virtual void getPolymorphed() const;

private:
    Servant();

};

std::ostream& operator<<(std::ostream& stream, const Servant& servant);

#endif /* SERVANT_HPP */
