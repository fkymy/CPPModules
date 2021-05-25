#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename T>
void iter(T* array, size_t len, void (*f)(const T&)) {
    for (size_t i = 0; i < len; ++i)
        (*f)(array[i]);
}

#endif /* ITER_HPP */
