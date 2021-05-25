#include <iostream>
#include "Data.hpp"

int main() {
    void * serializedData = serialize();
    Data * data = deserialize(serializedData);
    std::cout << data << std::endl;

    delete data->sp1;
    delete data->sp2;
    delete data;
    return 0;
}
