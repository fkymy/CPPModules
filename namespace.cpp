#include <iostream>
#include <cstring>

namespace Ft {
std::size_t strlen(const char* s) {
    const char* p = s;
    while (*p) ++p;
    return p - s;
}
}  // namespace Ft

int i = 0;
int main() {
    int i = 42;
    std::cout << "  i = " << i << "\n";        // 1
    std::cout << "::i = " << ::i << std::endl;  // 0

    std::cout << Ft::strlen("hello") << std::endl;
    std::cout << Ft::strlen("") << std::endl;
    std::cout << Ft::strlen("a") << std::endl;
    std::cout << std::strlen("hello") << std::endl;
    std::cout << std::strlen("") << std::endl;
    std::cout << std::strlen("a") << std::endl;
}
