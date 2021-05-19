#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap {
public:
    SuperTrap();
    SuperTrap(const std::string& name);
    SuperTrap(const SuperTrap& other);
    SuperTrap& operator=(const SuperTrap& other);
    ~SuperTrap();

    virtual void rangedAttack(const std::string& target);
    virtual void meleeAttack(const std::string& target);
};

#endif /* SUPERTRAP_HPP */
