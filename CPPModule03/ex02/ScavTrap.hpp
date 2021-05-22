#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap();
    explicit ScavTrap(const std::string& name);
    ~ScavTrap();

    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);

    void challengeNewcomer(std::string const & target);
};

#endif /* SCAVTRAP_HPP */
