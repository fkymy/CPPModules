#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap() {
    model = "NinjaTrap";
    hitPoints = 60;
    maxHitPoints = 60;
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
    rangedAttackDamage = 5;
    armorDamageReduction = 0;
    std::cout << "NinjaTrap Default constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string& name) : ClapTrap("NinjaTrap", name) {
    hitPoints = 60;
    maxHitPoints = 60;
    energyPoints = 120;
    maxEnergyPoints = 120;
    meleeAttackDamage = 60;
    rangedAttackDamage = 5;
    armorDamageReduction = 0;
    std::cout << "NinjaTrap Constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& other) : ClapTrap(other) {
    std::cout << "NinjaTrap Copy constructor called" << std::endl;
    *this = other;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& other) {
    std::cout << "NinjaTrap Assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

NinjaTrap::~NinjaTrap() { std::cout << "NinjaTrap Destructor called" << std::endl; }

void NinjaTrap::ninjaShoebox(const ClapTrap& trap) const {
    (void)trap;
    std::cout << model << " " << name << " attacks ClapTrap with ninja shoebox" << std::endl;
}

void NinjaTrap::ninjaShoebox(const FragTrap& trap) const {
    (void)trap;
    std::cout << model << " " << name << " attacks FragTrap with ninja shoebox" << std::endl;
}

void NinjaTrap::ninjaShoebox(const NinjaTrap& trap) const {
    (void)trap;
    std::cout << model << " " << name << " attacks NinjaTrap with ninja shoebox" << std::endl;
}

void NinjaTrap::ninjaShoebox(const ScavTrap& trap) const {
    (void)trap;
    std::cout << model << " " << name  << " attacks ScavTrap with ninja shoebox" << std::endl;

}
