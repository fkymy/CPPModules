#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    model = "SC4V-TP";
    energyPoints = 50;
    maxEnergyPoints = 50;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    std::cout << "SC4V-TP Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap("SC4V-TP", name) {
    energyPoints = 50;
    maxEnergyPoints = 50;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    std::cout << "SC4V-TP Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "SC4V-TP Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "SC4V-TP Assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "SC4V-TP Destructor called" << std::endl; }

void ScavTrap::challengeNewcomer(std::string const& target) {
    if (energyPoints < 25) {
        std::cout << "SC4V-TP " << name << " has not enough energy left. "
                  << std::endl;
        return;
    }

    const std::string challenges[5] = {"challenge1", "challenge2", "challenge3",
                                       "challenge4", "challenge5"};

    energyPoints -= 25;

    std::cout << "SC4V-TP " << name << " challenges " << target << " with "
              << challenges[rand() % 5] << ", causing " << rand() % 10
              << " points of damage!" << std::endl;
}
