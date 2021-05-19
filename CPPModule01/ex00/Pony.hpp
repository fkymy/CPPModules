#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

class Pony {
public:
    Pony(std::string name, int age, int weight);

    void run() const;

private:
    std::string name;
    int age;
    int weight;
};

#endif /* PONY_HPP */
