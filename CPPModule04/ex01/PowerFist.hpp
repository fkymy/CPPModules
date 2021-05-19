#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist: public AWeapon
{
    public:
        PowerFist();
        PowerFist(const PowerFist& other);
        PowerFist& operator=(const PowerFist& other);
        virtual ~PowerFist();

        virtual void attack() const;
};

#endif /* POWERFIST_HPP */
