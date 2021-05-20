#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter; // WHAT IS THIS

class AMateria
{
    protected:
        std::string _type;
        unsigned int _xp;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        std::string const & getType() const;
        unsigned int getXP() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif /* AMATERIA_HPP */
