#include <iostream>
#include <string>

#include "Array.hpp"

template <typename T>
void printArray(Array<T> &array) {
    std::cout << "[";
    if (array.size() == 0) {
        std::cout << "]" << std::endl;
        return;
    }

    for (unsigned int i = 0; i < array.size() - 1; ++i)
        std::cout << array[i] << ", ";
    std::cout << array[array.size() - 1] << "]" << std::endl;
}

template <typename T>
void printArray(const Array<T> &array) {
    std::cout << "[";
    if (array.size() == 0) {
        std::cout << "]" << std::endl;
        return;
    }

    for (unsigned int i = 0; i < array.size() - 1; ++i)
        std::cout << array[i] << ", ";
    std::cout << array[array.size() - 1] << "]" << std::endl;
}

class Test {
public:
    Test(int n = 0) : n(n) {}
    Test(const Test& other) {
        n = other.n;
    }
    Test& operator=(const Test& other) {
        if (this != &other) {
            n = other.n;
        }
        return *this;
    }
    int getN() const { return n; }
private:
    int n;
};

std::ostream& operator<<(std::ostream& os, const Test& t) {
    return os << t.getN();
}

int main() {
    {
        std::cout << "===== TEST INT =====" << std::endl;
        Array<int> array(8);
        printArray(array);

        for (unsigned int i = 0; i < array.size(); ++i) array[i] = i;
        printArray(array);

        try {
            std::cout << "accessing out of range..." << std::endl;
            array[8] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "accessing out of range..." << std::endl;
            array[-1] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "===== TEST STRING =====" << std::endl;
        Array<std::string> array(8);
        printArray(array);

        for (unsigned int i = 0; i < array.size(); ++i) array[i] = i + 'a';
        printArray(array);

        try {
            std::cout << "accessing out of range..." << std::endl;
            array[8] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "accessing out of range..." << std::endl;
            array[-1] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "===== TEST CLASS =====" << std::endl;
        Test t(42);
        Array<Test> array(8);
        printArray(array);

        for (unsigned int i = 0; i < array.size(); ++i) array[i] = t;
        printArray(array);

        try {
            std::cout << "accessing out of range..." << std::endl;
            array[8] = t;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "accessing out of range..." << std::endl;
            array[-1] = t;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "===== TEST CONST =====" << std::endl;
        Test t(42);
        const Array<Test> array(8);
        printArray(array);
    }

    {
        std::cout << "===== TEST DEFAULT CONSTRUCTOR =====" << std::endl;
        Array<float> array;
        std::cout << "array size after default constructor: " << array.size() << std::endl;
        printArray(array);

        try {
            std::cout << "accessing out of range..." << std::endl;
            array[0] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "accessing out of range..." << std::endl;
            array[-1] = 1;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "===== TEST COPY CONSTRUCTOR / ASSIGNMENT OP =====" << std::endl;
        Array<char> array1(8);
        std::cout << "array1 size: " << array1.size() << std::endl;

        for (unsigned int i = 0; i < 8; ++i) array1[i] = i + 'a';
        printArray(array1);

        Array<char> array2 = array1;
        std::cout << "array2 size: " << array2.size() << std::endl;
        printArray(array2);

        Array<char> array3(array2);
        std::cout << "array3 size: " << array3.size() << std::endl;
        printArray(array3);

        Array<char> array4;
        array4 = array3;
        std::cout << "array4 size: " << array4.size() << std::endl;
        printArray(array4);

        Array<char> array5;
        array4 = array5;
        std::cout << "array4 size: " << array4.size() << std::endl;
        printArray(array4);
    }
}
