#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
    protected:
        std::string name;
        int apcost;
        int damage;

        AWeapon();

    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(const AWeapon& other);
        AWeapon& operator=(const AWeapon& other);
        virtual ~AWeapon();

        std::string const & getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
};

#endif /* AWEAPON_HPP */
