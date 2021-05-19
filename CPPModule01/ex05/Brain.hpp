#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <sstream>
#include <string>

class Brain {
public:
    Brain();

    std::string identify() const;

private:
    int eq;
    int iq;
};

#endif /* BRAIN_HPP */
