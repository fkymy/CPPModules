#include "Peon.hpp"

Peon::Peon() {}

Peon::Peon(const std::string& name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon& other) : Victim(other) {
    std::cout << "Zog zog." << std::endl;
}

Peon& Peon::operator=(const Peon &other) {
    if (this != &other) {
        Victim::operator=(other);
    }
    return *this;
}

void Peon::getPolymorphed() const {
    std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const Peon& peon) {
    stream << "I'm " << peon.getName() << " and I like otters!" << std::endl;
    return stream;
}
