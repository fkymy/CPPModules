#include "Pony.hpp"

#include <iostream>
#include <string>

Pony::Pony(std::string name) : name(name) {}

void Pony::run() const {
    std::cout << name << ": 「うおおおおお」" << std::endl;
}
