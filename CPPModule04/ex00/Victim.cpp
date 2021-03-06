#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(const std::string& name) : name(name) {
    std::cout << "Some random victim called " << name << " just appeared!"
              << std::endl;
}

Victim::~Victim() {
    std::cout << "Victim " << name << " just died for no apparent reason!"
              << std::endl;
}

Victim::Victim(const Victim& other) {
    name = other.name;
    std::cout << "Some random victim called " << name << " just appeared!"
              << std::endl;
}

Victim& Victim::operator=(const Victim& other) {
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Victim& victim) {
    stream << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return stream;
}

const std::string& Victim::getName() const { return name; }

void Victim::getPolymorphed() const {
    std::cout << name << " has been turned into a cute little sheep!"
              << std::endl;
}
