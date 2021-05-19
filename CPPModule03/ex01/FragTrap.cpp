#include "FragTrap.hpp"

FragTrap::FragTrap()
    : hitPoints(100),
      maxHitPoints(100),
      energyPoints(100),
      maxEnergyPoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5) {
    std::cout << "FR4G-TP Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : name(name),
      hitPoints(100),
      maxHitPoints(100),
      energyPoints(100),
      maxEnergyPoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5) {
    std::cout << "FR4G-TP Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FR4G-TP Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FR4G-TP Assignment operator called" << std::endl;
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

FragTrap::~FragTrap() { std::cout << "FR4G-TP Destructor called" << std::endl; }

void FragTrap::rangedAttack(std::string const& target) const {
    std::cout << "FR4G-TP " << name << " attacks " << target
              << " at range, causing " << rangedAttackDamage
              << " points of damage!" << std::endl;
}
void FragTrap::meleeAttack(std::string const& target) const {
    std::cout << "FR4G-TP " << name << " attacks " << target
              << " in melee, causing " << meleeAttackDamage
              << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
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

    std::cout << "FR4G-TP " << name << " takes " << amount << " damage. " << hitPoints
              << "HP left." << std::endl;
}
void FragTrap::beRepaired(unsigned int amount) {
    if (hitPoints + amount > maxHitPoints) {
        hitPoints = maxHitPoints;
    } else {
        hitPoints += amount;
    }

    std::cout << "FR4G-TP " << name << " is being repaired. " << hitPoints
              << "HP left." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
    if (energyPoints < 25) {
        std::cout << "FR4G-TP " << name << " has not enough energy left. "
                  << std::endl;
        return;
    }

    const std::string attacks[5] = {"attack1", "attack2", "attack3", "attack4",
                                    "attack5"};

    energyPoints -= 25;

    std::cout << "FR4G-TP " << name << " attacks " << target << " with "
              << attacks[rand() % 5] << ", causing " << rand() % 10
              << " points of damage!" << std::endl;
}
