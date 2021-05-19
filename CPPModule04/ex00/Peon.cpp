#include "Peon.hpp"

Peon::Peon(const std::string& name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon& other) : Victim(other) {
}

Peon& Peon::operator=(const Peon &other) {
    if (this != &other) {
        Victim::operator=(other);
    }
    return *this;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
    std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}
