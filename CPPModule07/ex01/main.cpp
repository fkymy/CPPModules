#include <array>
#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void printArray(T* array, size_t len) {
    for (size_t i = 0; i < len; ++i)
        std::cout << static_cast<T>(array[i]) << std::endl;
}

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

void printInt(const int& n) {
    std::cout << n << std::endl;
}

void printString(const std::string& s) {
    std::cout << s << std::endl;
}

int main() {

    {
        std::cout << "===== TEST INT =====" << std::endl;
        int array[5] = { 1, 2, 3, 4, 5 };
        iter(array, 5, printElement);
        iter(array, 5, printInt);
    }

    {
        std::cout << "===== TEST STRING =====" << std::endl;
        std::string array[6] = {"stay", "awhile", "you",
                               "are",  "so",     "beautiful"};
        iter(array, 6, printElement);
        iter(array, 6, printString);
    }

    return 0;
}
