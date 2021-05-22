#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class ClapTrap {
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

public:
    ClapTrap();
    ClapTrap(const std::string& model, const std::string& name);
    virtual ~ClapTrap();

    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);

    virtual void rangedAttack(std::string const & target) const;
    virtual void meleeAttack(std::string const & target) const;
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_HPP */
