#include <new>
#include <iostream>

int main()
{
    unsigned int   wsa[5] = {1,2,3,4,5};

    // Use placement new (to use a known piece of memory).
    // In the way described above.
    unsigned int* wsp = new (wsa) unsigned int[5]();

    std::cout << wsa[0] << "\n";   // If these are zero then it worked as described.
    std::cout << wsa[1] << "\n";   // If they contain the numbers 1 - 5 then it failed.
    std::cout << wsa[2] << "\n";
    std::cout << wsa[3] << "\n";
    std::cout << wsa[4] << "\n";
}

