#include <iostream>
#include "Data.hpp"

int main() {
    std::cout << "sizeof Data: " << sizeof(Data) << std::endl;

    void * serializedData = serialize();

    Data * data = deserialize(serializedData);

    std::cout << data << std::endl;

    return 0;
}
