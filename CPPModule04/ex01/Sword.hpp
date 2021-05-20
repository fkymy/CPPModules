#ifndef SWORD_HPP
#define SWORD_HPP

#include <iostream>
#include "AWeapon.hpp"

class Sword: public AWeapon
{
    public:
        Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);
        virtual ~Sword();

        virtual void attack() const;
};

#endif /* SWORD_HPP */
