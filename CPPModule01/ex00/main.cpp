#include <new>
#include <iostream>
#include <string>

#include "Pony.hpp"

void ponyOnTheHeap() {
    Pony *pony = new (std::nothrow) Pony("specialweek", 9, 300);
    if (pony == 0) return;
    pony->run();
    delete pony;
}

void ponyOnTheStack() {
    Pony pony("haruurara", 12, 487);
    pony.run();
}

int main() {
    ponyOnTheHeap();
    ponyOnTheStack();

    system("leaks a.out");

    return 0;
}
