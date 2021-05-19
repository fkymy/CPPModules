#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : hitPoints(100),
      maxHitPoints(100),
      energyPoints(50),
      maxEnergyPoints(50),
      level(1),
      meleeAttackDamage(20),
      rangedAttackDamage(15),
      armorDamageReduction(3) {
    std::cout << "SC4V-TP Default constructor called" << std::endl;
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
    std::cout << "SC4V-TP Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "SC4V-TP Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "SC4V-TP Assignment operator called" << std::endl;
    if (this != &other) {
        hitPoints = other.hitPoints;
        maxHitPoints = other.maxHitPoints;
        energyPoints = other.energyPoints;
        maxEnergyPoints = other.maxEnergyPoints;
        level = other.level;
        name = other.name;
        meleeAttackDamage = other.meleeAttackDamage;
        rangedAttackDamage = other.rangedAttackDamage;
        armorDamageReduction = other.armorDamageReduction;
    }
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "SC4V-TP Destructor called" << std::endl; }

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

    std::cout << "SC4V-TP " << name << " is being repaired. " << hitPoints
              << "HP left." << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
    if (energyPoints < 25) {
        std::cout << "SC4V-TP " << name << " has not enough energy left. "
                  << std::endl;
        return;
    }

    const std::string challenges[5] = {"challenge1", "challenge2", "challenge3", "challenge4",
                                    "challenge5"};

    energyPoints -= 25;

    std::cout << "FR4G-TP " << name << " challenges " << target << " with "
              << challenges[rand() % 5] << ", causing " << rand() % 10
              << " points of damage!" << std::endl;
}
