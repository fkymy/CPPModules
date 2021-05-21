#include "Servant.hpp"

Servant::Servant() {}

Servant::Servant(const std::string& name) : Victim(name) {
    std::cout << "Servant Zog zog." << std::endl;
}

Servant::~Servant() { std::cout << "Servant Bleuark..." << std::endl; }

Servant::Servant(const Servant& other) : Victim(other) {
    std::cout << "Servant Zog zog." << std::endl;
}

Servant& Servant::operator=(const Servant& other) {
    if (this != &other) {
        Victim::operator=(other);
    }
    return *this;
}

void Servant::getPolymorphed() const {
    std::cout << getName() << " has been turned into a purple pony!"
              << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Servant& servant) {
    stream << "I'm " << servant.getName() << " and I like otters!" << std::endl;
    return stream;
}
