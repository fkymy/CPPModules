#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class ScavTrap {
public:
    ScavTrap();
    explicit ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void challengeNewcomer(std::string const & target);

private:
    std::string name;
    unsigned int hitPoints;
    unsigned int maxHitPoints;
    unsigned int energyPoints;
    unsigned int maxEnergyPoints;
    unsigned int level;
    unsigned int meleeAttackDamage;
    unsigned int rangedAttackDamage;
    unsigned int armorDamageReduction;

};

#endif /* SCAVTRAP_HPP */
