#include "Squad.hpp"

Squad::Squad() : count(0), marines(NULL) {}

Squad::Squad(const Squad& other) {
    copyOther(other);
}

Squad& Squad::operator=(const Squad& other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

void Squad::copyOther(const Squad& other) {
    count = other.count;
    marines = new ISpaceMarine*[count];
    for (int i = 0; i < count; ++i)
        marines[i] = other.getUnit(i)->clone();
}

void Squad::clear() {
    if (marines) {
        for (int i = 0; i < count; ++i) delete marines[i];
        delete[] marines;
        count = 0;
        marines = NULL;
    }
}

Squad::~Squad() {
    clear();
}

int Squad::getCount() const {
    return count;
}

ISpaceMarine* Squad::getUnit(int N) const {
    if (count == 0 || N < 0 || N >= count)
        return NULL;
    return marines[N];
}

int Squad::push(ISpaceMarine* marine) {
    ISpaceMarine** tmp;

    if (marine == NULL)
        return count;
    for (int i = 0; i < count; ++i) {
        if (marines[i] == marine)
            return count;
    }

    tmp = new ISpaceMarine*[count + 1];
    for (int i = 0; i < count; ++i)
        tmp[i] = marines[i];
    tmp[count] = marine;

    delete [] marines;
    marines = tmp;

    ++count;
    return count;
}
