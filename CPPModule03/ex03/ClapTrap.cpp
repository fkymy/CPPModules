#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : hitPoints(100),
      maxHitPoints(100),
      energyPoints(100),
      maxEnergyPoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& model, const std::string& name)
    : model(model),
      name(name),
      hitPoints(100),
      maxHitPoints(100),
      energyPoints(100),
      maxEnergyPoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5) {
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    if (this != &other) {
        model = other.model;
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

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::rangedAttack(std::string const& target) const {
    std::cout << model << " " << name << " attacks " << target
              << " at range, causing " << rangedAttackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const& target) const {
    std::cout << model << " " << name << " attacks " << target
              << " in melee, causing " << meleeAttackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
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

    std::cout << model << " " << name << " takes " << amount << " damage. "
              << hitPoints << "HP left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints + amount > maxHitPoints) {
        hitPoints = maxHitPoints;
    } else {
        hitPoints += amount;
    }

    std::cout << model << " " << name << " is being repaired. " << hitPoints
              << "HP left." << std::endl;
}
