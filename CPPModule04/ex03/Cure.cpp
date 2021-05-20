#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) {
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
