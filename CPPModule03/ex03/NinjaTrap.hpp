#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap {
public:
    NinjaTrap();
    NinjaTrap(const std::string& name);
    ~NinjaTrap();

    NinjaTrap(const NinjaTrap& other);
    NinjaTrap& operator=(const NinjaTrap& other);

    void ninjaShoebox(const ClapTrap& trap) const;
    void ninjaShoebox(const FragTrap& trap) const;
    void ninjaShoebox(const ScavTrap& trap) const;
    void ninjaShoebox(const NinjaTrap& trap) const;
};

#endif /* NINJATRAP_HPP */
