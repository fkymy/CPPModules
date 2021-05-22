#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class FragTrap {
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

public:
    FragTrap();
    explicit FragTrap(const std::string& name);
    ~FragTrap();

    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);

    void rangedAttack(std::string const & target) const;
    void meleeAttack(std::string const & target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const & target);
};

#endif /* FRAGTRAP_HPP */
