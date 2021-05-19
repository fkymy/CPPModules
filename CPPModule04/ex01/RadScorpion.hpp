#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
    public:
        RadScorpion();
        RadScorpion(const RadScorpion& other);
        RadScorpion& operator=(const RadScorpion& other);
        virtual ~RadScorpion();
};

#endif /* RADSCORPION_HPP */
