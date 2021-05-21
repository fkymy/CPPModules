#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria* _materias[4];

    void clear();
    void copyOther(const MateriaSource& other);

public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource &operator=(const MateriaSource& other);

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
