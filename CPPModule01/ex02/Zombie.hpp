#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
    Zombie();
    ~Zombie();

    void setName(std::string s);
    void setType(int val);
    void announce() const;
private:
    std::string name;
    int type;
};

#endif
