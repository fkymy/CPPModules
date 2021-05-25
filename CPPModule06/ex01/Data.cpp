#include "Data.hpp"

std::string* randomString(void) {
    std::string* ret = new std::string(10, 'a');
    for (std::string::iterator itr = ret->begin(); itr != ret->end(); ++itr)
        *itr = std::rand() % 26 + 'a';
    return ret;
}

void* serialize(void) {
    char* raw = new char[sizeof(Data)];

    std::srand(std::time(NULL));

    std::string* sp1 = randomString();
    int n = std::rand();
    std::string* sp2 = randomString();

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
