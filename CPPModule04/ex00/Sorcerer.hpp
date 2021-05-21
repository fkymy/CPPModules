#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>

#include "Victim.hpp"

class Sorcerer {
public:
    Sorcerer(const std::string& name, const std::string& title);
    ~Sorcerer();

    Sorcerer(const Sorcerer& other);
    Sorcerer& operator=(const Sorcerer& other);

    const std::string& getName() const;
    const std::string& getTitle() const;
    void polymorph(const Victim& victim) const;

private:
    Sorcerer();
    std::string name;
    std::string title;
};

std::ostream& operator<<(std::ostream& stream, const Sorcerer& sorcerer);

#endif /* SORCERER_HPP */
