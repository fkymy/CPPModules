#include "Servant.hpp"

Servant::Servant() {}

Servant::Servant(const std::string& name) : Victim(name) {
    std::cout << "Servant Zog zog." << std::endl;
}

Servant::Servant(const Servant& other) : Victim(other) {}

Servant& Servant::operator=(const Servant& other) {
    if (this != &other) {
        Victim::operator=(other);
    }
    return *this;
}

Servant::~Servant() { std::cout << "Servant Bleuark..." << std::endl; }

void Servant::getPolymorphed() const {
    std::cout << getName() << " has been turned into a purple pony!"
              << std::endl;
}
