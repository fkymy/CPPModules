#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    copyOther(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clear();
}

void MateriaSource::clear() {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i]) delete _materias[i];
        _materias[i] = NULL;
    }
}

void MateriaSource::copyOther(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] == NULL) {
            _materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
