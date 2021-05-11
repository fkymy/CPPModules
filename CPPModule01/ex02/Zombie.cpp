#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() {
    name = "yufukuya";
    type = 0;
}

Zombie::~Zombie() {

}

void Zombie::setName(std::string s) {
    name = s;
}

void Zombie::setType(int val) {
    type = val;
}

void Zombie::announce() const {
    std::string types[] = {"TypeA", "TypeB", "TypeC",
                           "TypeD", "TypeE", "TypeF"};

    std::cout << "< " << name << " (" << types[type % 6] << ")> "
              << "Braiiiiiiinnnssss..." << std::endl;
}
