#include "span.hpp"

#include <iostream>

Span::Span(unsigned int N) : N(N) {}

Span::~Span() { clear(); }

Span::Span(const Span& other) { copyOther(other); }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

void Span::clear() {
    N = 0;
    set.clear();
}

void Span::copyOther(const Span& other) {
    N = other.N;
    set = other.set;
}

void Span::addNumber(unsigned int num) {
    if (set.size() >= N) throw NoSpaceException();
    set.insert(num);
}

unsigned int Span::shortestSpan() const {
    if (set.size() < 2) throw TooLittleException();

    std::multiset<unsigned int>::const_iterator itr = set.begin();
    std::multiset<unsigned int>::reverse_iterator rItr = set.rbegin();
    unsigned int shortest = *rItr - *itr;

    unsigned int prev = *itr;
    ++itr;
    for (; itr != set.end(); ++itr) {
        unsigned int diff = *itr - prev;
        if (diff < shortest) shortest = diff;
        prev = *itr;
    }
    return shortest;
}

unsigned int Span::longestSpan() const {
    if (set.size() < 2) throw TooLittleException();

    std::multiset<unsigned int>::const_iterator itr = set.begin();
    std::multiset<unsigned int>::reverse_iterator rItr = set.rbegin();
    return *rItr - *itr;
}

Span::NoSpaceException::NoSpaceException() {}

const char* Span::NoSpaceException::what() const throw() {
    return "Error: Span: no space left";
}

Span::TooLittleException::TooLittleException() {}

const char* Span::TooLittleException::what() const throw() {
    return "Error: Span: span too little";
}
