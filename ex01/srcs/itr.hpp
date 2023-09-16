#ifndef ITR_HPP
#define ITR_HPP

#include <iostream>

template <typename T>
void printPtr(T* ptr)
{
    std::cout << ptr << " is ptr" << std::endl;
}


template <typename T>
void itr(T* arr, std::size_t size, void (*f)(T*))
{
    for (std::size_t i = 0; i < size; i++)
    { 
        f(&arr[i]);
    }
}

template <typename T>
void itr(const T* arr, std::size_t size, void (*f)(const T*))
{
    for (std::size_t i = 0; i < size; i++)
    { 
        f(&arr[i]);
    }
}

#endif