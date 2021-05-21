#ifndef SWORD_HPP
#define SWORD_HPP

#include <iostream>
#include "AWeapon.hpp"

class Sword: public AWeapon
{
    public:
        Sword();
        virtual ~Sword();

        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

        virtual void attack() const;
};

#endif /* SWORD_HPP */
