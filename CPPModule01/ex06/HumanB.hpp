#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
public:
    explicit HumanB(std::string name);

    void setWeapon(const Weapon& w);
    void attack() const;

private:
    std::string name;
    const Weapon* weapon;
};

#endif /* HUMANB_HPP */
