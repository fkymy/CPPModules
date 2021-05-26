#include <string>
#include <cstdlib>
#include <iostream>

void* operator new(std::size_t n) throw() {
    std::cout << "[Allocating " << n << " bytes]";
    return malloc(n);
}

void operator delete(void* p) throw() {
    free(p);
}

int main() {
    for (size_t i = 0; i < 128; ++i) {
        std::cout << i << ": " << std::string(i, 'a') << std::endl;
    }
}
