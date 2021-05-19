#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
    public:
        SuperMutant();
        SuperMutant(const SuperMutant& other);
        SuperMutant& operator=(const SuperMutant& other);
        virtual ~SuperMutant();

        virtual void takeDamage(int);
};

#endif /* SUPERMUTANT_HPP */
