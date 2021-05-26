#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span {
public:
    explicit Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    void addNumber(unsigned int num);

    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end) {
        for (InputIterator itr = begin; itr != end; ++itr)
            addNumber(*itr);
    }

    void clear();
    void copyOther(const Span& other);

    class NoSpaceException : public std::exception {
    public:
        NoSpaceException();
        virtual const char* what() const throw();
    };

    class TooLittleException : public std::exception {
    public:
        TooLittleException();
        virtual const char* what() const throw();
    };

private:
    unsigned int N;
    std::set<unsigned int> set;
};

#endif /* SPAN_HPP */
