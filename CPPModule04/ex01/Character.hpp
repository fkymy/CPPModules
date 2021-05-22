#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
    private:
        std::string name;
        int ap;
        AWeapon* weapon;

        Character();

    public:
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string const & getName() const;
        int getAP() const;
        AWeapon* getWeapon() const;
};

std::ostream& operator<<(std::ostream& stream, const Character& character);

#endif /* CHARACTER_HPP */
