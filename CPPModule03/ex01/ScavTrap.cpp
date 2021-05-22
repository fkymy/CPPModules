#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : name("default scav"),
      hitPoints(100),
      maxHitPoints(100),
      energyPoints(50),
      maxEnergyPoints(50),
      level(1),
      meleeAttackDamage(20),
      rangedAttackDamage(15),
      armorDamageReduction(3) {
    std::cout << "SC4V-TP default constructor: I'm not to let ANYONE in "
                 "through here! "
              << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : name(name),
      hitPoints(100),
      maxHitPoints(100),
      energyPoints(50),
      maxEnergyPoints(50),
      level(1),
      meleeAttackDamage(20),
      rangedAttackDamage(15),
      armorDamageReduction(3) {
    std::cout << "SC4V-TP constructor: I'm not to let ANYONE in through here! "
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout
        << "SC4V-TP copy constructor: I'm not to let ANYONE in through here! "
        << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    maxHitPoints = other.maxHitPoints;
    energyPoints = other.energyPoints;
    maxEnergyPoints = other.maxEnergyPoints;
    level = other.level;
    meleeAttackDamage = other.meleeAttackDamage;
    rangedAttackDamage = other.rangedAttackDamage;
    armorDamageReduction = other.armorDamageReduction;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "SC4V-TP Assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        maxHitPoints = other.maxHitPoints;
        energyPoints = other.energyPoints;
        maxEnergyPoints = other.maxEnergyPoints;
        level = other.level;
        meleeAttackDamage = other.meleeAttackDamage;
        rangedAttackDamage = other.rangedAttackDamage;
        armorDamageReduction = other.armorDamageReduction;
    }
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "SC4V-TP: bye bye" << std::endl; }

void ScavTrap::rangedAttack(std::string const& target) const {
    std::cout << "SC4V-TP " << name << " attacks " << target
              << " at range, causing " << rangedAttackDamage
              << " points of damage!" << std::endl;
}
void ScavTrap::meleeAttack(std::string const& target) const {
    std::cout << "SC4V-TP " << name << " attacks " << target
              << " in melee, causing " << meleeAttackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (armorDamageReduction > amount) {
        amount = 0;
    } else {
        amount -= armorDamageReduction;
    }

    if (amount > hitPoints) {
        hitPoints = 0;
    } else {
        hitPoints -= amount;
    }

    std::cout << "SC4V-TP " << name << " takes " << amount << " damage. "
              << hitPoints << "HP left." << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount) {
    if (hitPoints + amount > maxHitPoints) {
        hitPoints = maxHitPoints;
    } else {
        hitPoints += amount;
    }

    if (energyPoints + amount > maxEnergyPoints) {
        energyPoints = maxEnergyPoints;
    } else {
        energyPoints += amount;
    }

    std::cout << "SC4V-TP " << name << " is being repaired. " << hitPoints
              << "HP left and " << energyPoints << "energy left." << std::endl;
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
