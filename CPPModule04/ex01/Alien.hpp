#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class Alien : public Enemy
{
    public:
        Alien();
        virtual ~Alien();

        Alien(const Alien& other);
        Alien& operator=(const Alien& other);
};

#endif /* ALIEN_HPP */
