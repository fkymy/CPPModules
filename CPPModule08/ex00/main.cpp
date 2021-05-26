#include <iostream>
#include "easyfind.hpp"
#include <array>
#include <vector>
#include <set>

int main() {
    {
        std::cout << "===== TEST ARRAY =====" << std::endl;
        std::array<int, 8> array = { 1, 1, 2, 3, 3, 4, 5, 6 };

        std::array<int, 8>::const_iterator itr = easyfind(array, 0);
        std::cout << ((itr == array.end()) ? "NOT FOUND" : "FOUND") << std::endl;

        std::array<int, 8>::const_iterator itr2 = easyfind(array, 5);
        std::cout << ((itr2 == array.end()) ? "NOT FOUND" : "FOUND") << std::endl;
    }

    {
        std::cout << "===== TEST VECTOR =====" << std::endl;
        std::vector<int> v;

        std::vector<int>::const_iterator itr = easyfind(v, -1);
        std::cout << ((itr == v.end()) ? "NOT FOUND" : "FOUND") << std::endl;

        std::vector<int>::const_iterator itr2 = easyfind(v, 6);
        std::cout << ((itr2 == v.end()) ? "NOT FOUND" : "FOUND") << std::endl;
    }

    {
        std::cout << "===== TEST VECTOR =====" << std::endl;
        std::vector<int> v(8, 0);
        v.push_back(6);

        std::vector<int>::const_iterator itr = easyfind(v, -1);
        std::cout << ((itr == v.end()) ? "NOT FOUND" : "FOUND") << std::endl;

        std::vector<int>::const_iterator itr2 = easyfind(v, 6);
        std::cout << ((itr2 == v.end()) ? "NOT FOUND" : "FOUND") << std::endl;
    }

    {
        std::cout << "===== TEST SET =====" << std::endl;
        std::set<int> set;

        std::set<int>::const_iterator itr = easyfind(set, -1);
        std::cout << ((itr == set.end()) ? "NOT FOUND" : "FOUND") << std::endl;

        std::set<int>::const_iterator itr2 = easyfind(set, 3);
        std::cout << ((itr2 == set.end()) ? "NOT FOUND" : "FOUND") << std::endl;
    }

    {
        std::cout << "===== TEST SET =====" << std::endl;
        std::set<int> set;
        set.insert(3);

        std::set<int>::const_iterator itr = easyfind(set, -1);
        std::cout << ((itr == set.end()) ? "NOT FOUND" : "FOUND") << std::endl;

        std::set<int>::const_iterator itr2 = easyfind(set, 3);
        std::cout << ((itr2 == set.end()) ? "NOT FOUND" : "FOUND") << std::endl;
    }

    return 0;
}
