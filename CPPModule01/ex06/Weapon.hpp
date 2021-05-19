#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    explicit Weapon(const std::string& type);

    const std::string& getType() const;
    void setType(const std::string& s);

private:
    std::string type;
};

#endif /* WEAPON_HPP */
