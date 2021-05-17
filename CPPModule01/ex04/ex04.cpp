#include <iostream>
#include <string>

int main() {
    std::string s = "HI THIS IS BRAIN";
    std::string* sp = &s;
    std::string& sr = s;

    std::cout << *sp << std::endl;
    std::cout << sr << std::endl;

    return 0;
}
