#include "Alien.hpp"

Alien::Alien() : Enemy(2, "Alien") {
    std::cout <<  "Hello I am Alien" << std::endl;
}

Alien::~Alien() {
    std::cout << "ahh..." << std::endl;
}

Alien::Alien(const Alien& other) : Enemy(other) {
    std::cout <<  "Hello I am Alien" << std::endl;
}

Alien& Alien::operator=(const Alien &other) {
    if (this != &other) {
        Enemy::operator=(other);
    }
    return *this;
}
