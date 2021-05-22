#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(), FragTrap(), NinjaTrap() {
    model = "SuperTrap";
    name = "default super";
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
    rangedAttackDamage = 20;
    armorDamageReduction = 5;
    std::cout << "SuperTrap Default constructor called" << std::endl;
}

SuperTrap::SuperTrap(const std::string& name): ClapTrap("SuperTrap", name), FragTrap(name), NinjaTrap() {
    model = "SuperTrap";
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
    rangedAttackDamage = 20;
    armorDamageReduction = 5;
    std::cout << "SuperTrap constructor called" << std::endl;
}

SuperTrap::~SuperTrap() {
    std::cout << "SuperTrap Destructor called" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& other) : ClapTrap(other), FragTrap(other), NinjaTrap(other) {
    std::cout << "SuperTrap Copy constructor called" << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& other) {
    std::cout << "SuperTrap Assignment operator called" << std::endl;
    if (this != &other) {
        FragTrap::operator=(other);
        NinjaTrap::operator=(other);
    }
    return *this;
}

void SuperTrap::rangedAttack(std::string const & target) const {
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) const {
    NinjaTrap::meleeAttack(target);
}
