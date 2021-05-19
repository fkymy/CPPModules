#include "Pony.hpp"

Pony::Pony(std::string name, int age, int weight)
    : name(name), age(age), weight(weight) {}

void Pony::run() const {
    std::cout << name << "(age: " << age << ", weight: " << weight
              << "): 「うおおおおお」" << std::endl;
}
