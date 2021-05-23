#include "Data.hpp"

void* serialize(void) {
    char* raw = new char[sizeof(Data)];
    bzero(raw, sizeof(Data));

    std::string* sp1 = new std::string("first random string");
    int n = 42;
    std::string* sp2 = new std::string("second random string");

   *reinterpret_cast<std::string**>(raw) = sp1;
    *(reinterpret_cast<int*>(raw+8)) = n;
   *reinterpret_cast<std::string**>(raw+8+4) = sp2;

    return raw;
}

Data* deserialize(void * raw) {
    Data *data = new Data;
    data->sp1 = *reinterpret_cast<std::string**>(raw);
    data->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
    data->sp2 = *reinterpret_cast<std::string**>(static_cast<char*>(raw) + 8 + 4);
    return data;
}

std::ostream& operator<<(std::ostream& os, Data* d) {
    os << "Data { ";
    os << "sp1: " << *(d->sp1) << ", ";
    os << "n: " << d->n << ", ";
    os << "sp2: " << *(d->sp2) << " }";
    os << std::endl;
    return os;
}
