#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data {
    std::string* sp1;
    int n;
    std::string* sp2;
};

void* serialize();
Data* deserialize(void* raw);

std::ostream& operator<<(std::ostream& os, Data* d);

#endif /* DATA_HPP */
