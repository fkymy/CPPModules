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

private:
    Victim();
    std::string name;
    std::string title;
};

std::ostream& operator<<(std::ostream& stream, const Victim& victim);

#endif /* VICTIM_HPP */
