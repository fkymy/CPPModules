#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(const PowerFist& other) : AWeapon(other) {}

PowerFist& PowerFist::operator=(const PowerFist& other) {
    if (this != &other) {
        AWeapon::operator=(other);
    }
    return *this;
}

PowerFist::~PowerFist() {};

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
