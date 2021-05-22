#include "FragTrap.hpp"

FragTrap::FragTrap()
    : name("default"),
      hitPoints(100),
      maxHitPoints(100),
      energyPoints(100),
      maxEnergyPoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5) {
    std::cout << "FR4G-TP default constructor: Hey, best friend!" << std::endl;
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
    std::cout << "FR4G-TP constructor: Hey, best friend!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP Yessss, look into my eyes. You're getting sleepy. "
                 "You're getting... zzzzzz... Zzzzzz..."
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FR4G-TP copy constructor: Hey, best friend!" << std::endl;
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

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FR4G-TP assignment operator: Hey, best friend!" << std::endl;
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

    std::cout << "FR4G-TP " << name << " takes " << amount << " damage. "
              << hitPoints << "HP left." << std::endl;
}
void FragTrap::beRepaired(unsigned int amount) {
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

    std::cout << "FR4G-TP " << name << " is being repaired. " << hitPoints
              << "HP left and " << energyPoints << "energy left." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
    const std::string attacks[] = {"Nade out!", "Hot potato!",
                                   "Take a chill pill!", "Eat bomb!",
                                   "Freezy peezy!"};

    if (energyPoints < 25) {
        std::cout << "FR4G-TP " << name << " has not enough energy left. "
                  << std::endl;
        return;
    }

    energyPoints -= 25;

    std::cout << "FR4G-TP " << name << " attacks " << target << " with "
              << attacks[rand() % 5] << ", causing " << rand() % 10
              << " points of damage!" << std::endl;
}
