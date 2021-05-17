#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
public:
    Pony(std::string name);

    void run() const;

private:
    std::string name;
};

#endif /* PONY_HPP */
