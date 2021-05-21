#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
    std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& other) : Enemy(other) {
    std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
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
    amount = (amount < 3) ? 0 : amount - 3;
    Enemy::takeDamage(amount);
}
