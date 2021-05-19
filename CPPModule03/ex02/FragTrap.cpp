#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    model = "FR4G-TP";
    std::cout << "FR4G-TP Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap("FR4G-TP", name) {
    std::cout << "FR4G-TP Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FR4G-TP Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FR4G-TP Assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() { std::cout << "FR4G-TP Destructor called" << std::endl; }

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
