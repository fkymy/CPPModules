#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
    std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& other) : Enemy() {
    *this = other;
}

SuperMutant& SuperMutant::operator=(const SuperMutant &other) {
    if (this != &other) {
        Enemy::operator=(other);
    }
    return *this;
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int amount) {
    Enemy::takeDamage(amount - 3);
}
