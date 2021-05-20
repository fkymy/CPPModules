#ifndef SERVANT_HPP
#define SERVANT_HPP

#include <iostream>

#include "Victim.hpp"

class Servant: public Victim {
public:
    Servant(const std::string& name);
    Servant(const Servant& other);
    Servant& operator=(const Servant& other);
    ~Servant();

    virtual void getPolymorphed() const;

private:
    Servant();

};

#endif /* SERVANT_HPP */
