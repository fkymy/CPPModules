#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
    : name(name), apcost(apcost), damage(damage) {}

AWeapon::AWeapon(const AWeapon& other) {
    *this = other;
}

AWeapon& AWeapon::operator=(const AWeapon& other) {
    if (this != &other) {
        name = other.name;
        damage = other.damage;
        apcost = other.apcost;
    }
    return *this;
}

AWeapon::~AWeapon() {}

std::string const& AWeapon::getName() const { return name; }

int AWeapon::getAPCost() const { return apcost; }

int AWeapon::getDamage() const { return damage; }

