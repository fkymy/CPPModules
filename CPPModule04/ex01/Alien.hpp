#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class Alien : public Enemy
{
    public:
        Alien();
        Alien(const Alien& other);
        Alien& operator=(const Alien& other);
        virtual ~Alien();
};

#endif /* ALIEN_HPP */
