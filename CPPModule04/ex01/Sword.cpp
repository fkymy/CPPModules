#include "Sword.hpp"

Sword::Sword() : AWeapon("Sword", 1, 30) {}

Sword::Sword(const Sword& other) : AWeapon(other) {}

Sword& Sword::operator=(const Sword& other) {
    if (this != &other) {
        AWeapon::operator=(other);
    }
    return *this;
}

Sword::~Sword() {};

void Sword::attack() const {
    std::cout << "* Slash! *" << std::endl;
}
