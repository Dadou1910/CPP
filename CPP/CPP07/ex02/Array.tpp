#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : size(n)
{
    elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : size(other.size)
{
    elements = new T[size];
    for (unsigned int i = 0; i < size; i++)
        elements[i] = other.elements[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] elements;
        size = other.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; i++)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= size)
        throw std::out_of_range("Index out of bounds!");
    return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= size)
        throw std::out_of_range("Index out of bounds!");
    return elements[index];
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}
