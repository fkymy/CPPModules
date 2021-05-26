#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& collection, int val) {
    return std::find(collection.begin(), collection.end(), val);
}

#endif /* EASYFIND_HPP */
