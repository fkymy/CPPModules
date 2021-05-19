#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(const std::string& name, const std::string& title)
    : name(name), title(title) {
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() {
    std::cout << name << ", " << title
              << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& other) {
    *this = other;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& other) {
    if (this != &other) {
        name = other.name;
        title = other.title;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Sorcerer& sorcerer) {
    stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
           << ", and I like ponies!" << std::endl;
    return stream;
}

const std::string& Sorcerer::getName() const { return name; }

const std::string& Sorcerer::getTitle() const { return title; }

void Sorcerer::polymorph(const Victim &victim) const {
    victim.getPolymorphed();
}
