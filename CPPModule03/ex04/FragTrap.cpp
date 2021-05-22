#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    model = "FR4G-TP";
    name = "default frag";
    std::cout << "FR4G-TP default constructor: Hey, best friend!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP Yessss, look into my eyes. You're getting sleepy. "
                 "You're getting... zzzzzz... Zzzzzz..."
              << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap("FR4G-TP", name) {
    std::cout << "FR4G-TP constructor: Hey, best friend!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FR4G-TP copy constructor: Hey, best friend!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FR4G-TP assignment operator: Hey, best friend!" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
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
