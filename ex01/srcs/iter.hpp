#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <exception>

template <typename T>
void iter(T* arr, std::size_t size, void (*f)(T*))
{
    if (arr == NULL)
        throw std::runtime_error("arr is NULL");
    if (f == NULL)
        throw std::runtime_error("func pointer is NULL");
    for (std::size_t i = 0; i < size; i++)
    { 
        f(&arr[i]);
    }
}

template <typename T>
void iter(const T* arr, std::size_t size, void (*f)(const T*))
{
    if (arr == NULL)
        throw std::runtime_error("arr is NULL");
    if (f == NULL)
        throw std::runtime_error("func pointer is NULL");
    for (std::size_t i = 0; i < size; i++)
    {
        f(&arr[i]);
    }
}

#endif