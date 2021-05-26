#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
public:
    explicit Array(unsigned int n = 0);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);

    unsigned int size() const;
    void clear();
    void copyOther(const Array& other);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

private:
    T* array_;
    unsigned int size_;
};

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::~Array() {
    clear();
}

template <typename T>
Array<T>::Array(const Array& other) {
    copyOther(other);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

template <typename T>
void Array<T>::clear() {
    delete[] array_;
}

template <typename T>
void Array<T>::copyOther(const Array<T>& other) {
    array_ = new T[other.size()];
    size_ = other.size();
    for (unsigned int i = 0; i < size_; ++i)
        array_[i] = other.array_[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size_)
        throw std::out_of_range("Array: out of range");
    return array_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_)
        throw std::out_of_range("Array: out of range");
    return array_[index];
}

#endif /* ARRAY_HPP */
