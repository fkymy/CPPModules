#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string& name) : _name(name) {}

Character::Character(const Character& other) {
    _name = other._name;
    _inventoryCount = other._inventoryCount;

    for (int i = 0; i < _inventoryCount; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character &other) {
    if (this != &other) {
        // clear()
        for (int i = 0; i < _inventoryCount; ++i)
            delete _inventory[i];

        _name = other._name;
        _inventoryCount = other._inventoryCount;
        for (int i = 0; i < _inventoryCount; ++i) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    clear();
}

void Character::clear() {
    for (int i = 0; i < _inventoryCount; ++i)
        delete _inventory[i];
}

void Character::equip(AMateria* m) {
    if (_inventoryCount == 4 || m == NULL)
        return;
    _inventory[_inventoryCount] = m;
    ++_inventoryCount;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    if (_inventory[idx]) {
        _inventory[idx] = NULL;
        --_inventoryCount;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}

std::string const& Character::getName() const { return _name; }
