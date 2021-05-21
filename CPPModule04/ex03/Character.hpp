#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];

    Character();

public:
    Character(const std::string& name);
    virtual ~Character();

    Character(const Character& other);
    Character& operator=(const Character& other);

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    void clear();
    void copyOther(const Character& other);
};

#endif /* CHARACTER_HPP */
