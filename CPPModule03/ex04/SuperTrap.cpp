#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap() {
    model = "SuperTrap";
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
}

SuperTrap::SuperTrap(const std::string& name): ClapTrap("SuperTrap", name) {
    model = "SuperTrap";
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
}

SuperTrap::~SuperTrap() {
    std::cout << "SuperTrap Destructor called" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& other) : ClapTrap(other) {
    std::cout << "SuperTrap Copy constructor called" << std::endl;
    *this = other;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& other) {
    std::cout << "SuperTrap Assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void SuperTrap::rangedAttack(const std::string& target) {
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string& target) {
    NinjaTrap::meleeAttack(target);
}
