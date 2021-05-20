#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
public:
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    void copyOther();
    void clear();

private:
    std::string _name;
    AMateria* _inventory[4];
    int _inventoryCount;
};

#endif /* CHARACTER_HPP */
