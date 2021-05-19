#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

void HumanB::setWeapon(const Weapon& w) { weapon = &w; }

void HumanB::attack() const {
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}
