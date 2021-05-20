#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) {
    _materiaCount = other._materiaCount;
    for (int i = 0; i < _materiaCount; ++i) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < _materiaCount; ++i)
            delete _materias[i];
        _materiaCount = other._materiaCount;
        for (int i = 0; i < _materiaCount; ++i) {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < _materiaCount; ++i)
        delete _materias[i];
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL || _materiaCount >= 4)
        return;
    _materias[_materiaCount] = m;
    ++_materiaCount;
}

AMateria* MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < _materiaCount; ++i) {
        if (_materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
