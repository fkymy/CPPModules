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
    ~SuperTrap();

    SuperTrap(const SuperTrap& other);
    SuperTrap& operator=(const SuperTrap& other);

    virtual void rangedAttack(std::string const & target) const;
    virtual void meleeAttack(std::string const & target) const;
};

#endif /* SUPERTRAP_HPP */
