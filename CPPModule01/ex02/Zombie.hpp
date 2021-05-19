#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
public:
    Zombie();

    void announce() const;
    void setName(const std::string& s);
    void setType(int val);

private:
    std::string name;
    int type;
};

#endif
