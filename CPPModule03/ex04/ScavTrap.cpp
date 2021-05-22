#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    model = "SC4V-TP";
    name = "default scav";
    energyPoints = 50;
    maxEnergyPoints = 50;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    std::cout << "SC4V-TP default constructor: I'm not to let ANYONE in "
                 "through here! "
              << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap("SC4V-TP", name) {
    energyPoints = 50;
    maxEnergyPoints = 50;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    std::cout << "SC4V-TP constructor: I'm not to let ANYONE in through here! "
              << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "SC4V-TP: bye bye" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout
        << "SC4V-TP copy constructor: I'm not to let ANYONE in through here! "
        << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "SC4V-TP Assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::challengeNewcomer(std::string const& target) {
    const std::string challenges[5] = {"Death from Above", "Eagle Eye",
                                       "Roger Slamjet", "Slampage!",
                                       "Dragon Punch"};

    if (energyPoints < 25) {
        std::cout << "SC4V-TP " << name << " has not enough energy left. "
                  << std::endl;
        return;
    }

    energyPoints -= 25;

    std::cout << "FR4G-TP " << name << " challenges " << target << " with "
              << challenges[rand() % 5] << std::endl;
}
