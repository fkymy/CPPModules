#include "span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "===== MY TESTS =====" << std::endl;
    std::cout << std::endl;

    std::srand(std::time(NULL));

    std::cout << "===== TEST BASICS =====" << std::endl;
    {

        Span s1 = Span(1000000);
        for (int i = 0; i < 1000000; ++i) {
            s1.addNumber(42);
        }

        std::cout << s1.shortestSpan() << std::endl;
        std::cout << s1.longestSpan() << std::endl;
    }

    {

        Span s1 = Span(1000000);
        for (int i = 0; i < 1000000; ++i) {
            s1.addNumber(static_cast<unsigned int>(rand() % 1000000));
        }

        std::cout << s1.shortestSpan() << std::endl;
        std::cout << s1.longestSpan() << std::endl;
    }

    {
        Span s1 = Span(0);
        try {
            for (int i = 0; i < 10; ++i) {
                s1.addNumber(static_cast<unsigned int>(rand() % 10));
            }

            std::cout << s1.shortestSpan() << std::endl;
            std::cout << s1.longestSpan() << std::endl;

        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        Span s1 = Span(0);

        try {
            std::cout << s1.shortestSpan() << std::endl;
            std::cout << s1.longestSpan() << std::endl;

        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        Span s1 = Span(42);
        s1.addNumber(42);

        try {
            std::cout << s1.shortestSpan() << std::endl;
            std::cout << s1.longestSpan() << std::endl;

        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "===== TEST RANGE =====" << std::endl;
    {
        Span s2 = Span(100);
        std::vector<unsigned int> v;
        for (int i = 0; i < 100; ++i) {
            v.push_back(i);
        }

        try {
            s2.addNumber(v.begin(), v.end());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << s2.shortestSpan() << std::endl;
        std::cout << s2.longestSpan() << std::endl;
    }

    {
        Span s2 = Span(100);
        std::vector<unsigned int> v(100, 42);

        try {
            s2.addNumber(v.begin(), v.end());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << s2.shortestSpan() << std::endl;
        std::cout << s2.longestSpan() << std::endl;
    }

    {
        Span s2 = Span(100);
        std::vector<unsigned int> v;
        for (int i = 0; i < 101; ++i) {
            v.push_back(i);
        }

        try {
            s2.addNumber(v.begin(), v.end());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << s2.shortestSpan() << std::endl;
        std::cout << s2.longestSpan() << std::endl;
    }

    return 0;
}
