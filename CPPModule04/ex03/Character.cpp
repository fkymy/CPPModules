#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string& name) : _name(name) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const Character& other) {
    copyOther(other);
}

Character& Character::operator=(const Character &other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

Character::~Character() {
    clear();
}

void Character::clear() {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i]) delete _inventory[i];
        _inventory[i] = NULL;
    }
}

void Character::copyOther(const Character& other) {
    _name = other._name;
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

void Character::equip(AMateria* m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}

std::string const& Character::getName() const { return _name; }
