#include "Character.hpp"

Character::Character() {}

Character::Character(std::string const& name) : name(name), ap(40), weapon(0) {}

Character::Character(const Character& other) {
    *this = other;
}

Character& Character::operator=(const Character &other) {
    if (this != &other) {
        name = other.name;
        ap = other.ap;
        weapon = other.weapon;
    }
    return *this;
}

Character::~Character() {}

void Character::recoverAP() {
    ap += 10;
    if (ap > 40) ap = 40;
}

void Character::equip(AWeapon* newWeapon) {
    weapon = newWeapon;
}

void Character::attack(Enemy* enemy) {
    if (weapon == 0 || enemy == 0) return;
    if (ap < weapon->getAPCost()) return;
    std::cout << name << " attacks " << enemy->getType() << " with a "
              << weapon->getName() << std::endl;
    weapon->attack();
    enemy->takeDamage(weapon->getDamage());
    ap -= weapon->getAPCost();
    if (ap < 0) ap = 0;
    if (enemy->getHP() <= 0) delete enemy;
}

std::string const& Character::getName() const { return name; }

int Character::getAP() const { return ap; }

AWeapon* Character::getWeapon() const { return weapon; }

std::ostream& operator<<(std::ostream& stream, const Character& character) {
    stream << character.getName() << " has " << character.getAP() << " AP and ";
    if (character.getWeapon())
        stream << "wields a " << character.getWeapon()->getName() << std::endl;
    else
        stream << "is unarmed" << std::endl;
    return stream;
}
