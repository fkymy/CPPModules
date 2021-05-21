#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
    std::cout <<  "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& other) : Enemy(other) {
    std::cout <<  "* click click click *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion &other) {
    if (this != &other) {
        Enemy::operator=(other);
    }
    return *this;
}

RadScorpion::~RadScorpion() {
    std::cout <<  "* SPROTCH *" << std::endl;
}
