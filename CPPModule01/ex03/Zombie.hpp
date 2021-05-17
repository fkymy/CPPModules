#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
    Zombie();

    void announce() const;
    void setName(std::string s);
    void setType(int val);

private:
    std::string name;
    int type;
};

#endif
