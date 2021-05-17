#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() {
    name = "yufukuya";
    type = 0;
}

void Zombie::setName(std::string s) {
    name = s;
}

void Zombie::setType(int val) {
    type = val;
}

void Zombie::announce() const {
    std::cout << "<" << name << " (" << type << ")> "
              << "Braiiiiiiinnnssss..." << std::endl;
}
