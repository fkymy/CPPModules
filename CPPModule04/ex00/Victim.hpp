#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim {
public:
    Victim(const std::string& name);
    Victim(const Victim& other);
    Victim& operator=(const Victim& other);
    virtual ~Victim();

    const std::string& getName() const;
    virtual void getPolymorphed() const;

protected:
    Victim();
    std::string name;
};

std::ostream& operator<<(std::ostream& stream, const Victim& victim);

#endif /* VICTIM_HPP */
