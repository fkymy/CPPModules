#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(const std::string& model, const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string model;
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

#endif /* CLAPTRAP_HPP */
