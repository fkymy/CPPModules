#include "Sword.hpp"

Sword::Sword() : AWeapon("Sword", 1, 30) {}

Sword::~Sword() {};

Sword::Sword(const Sword& other) : AWeapon(other) {}

Sword& Sword::operator=(const Sword& other) {
    if (this != &other) {
        AWeapon::operator=(other);
    }
    return *this;
}

void Sword::attack() const {
    std::cout << "* Slash! *" << std::endl;
}
