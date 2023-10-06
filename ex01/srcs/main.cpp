#include "iter.hpp"

template <typename T>
void printPtr(T* ptr)
{
    std::cout << ptr << " is ptr" << std::endl;
}

void    mult(int *a)
{
    std::cout << "mult() called: " << *a << " --> " << *a * 2 << std::endl;
    (*a) *= 2;
}

void    printer(int const *a)
{
    std::cout << "printer() called: "<< *a << std::endl;
}

void    testNormalArray()
{
    std::cout << "===== testNormalArray ====" << std::endl;
    int array[] = {0, 1, 2};
    std::size_t size = 3;
    iter(&array[0], size, printer);
    iter(&array[0], size, mult);
    iter(&array[0], size, printer);
    std::cout << std::endl << std::endl << std::endl;
}

void    testConstArray()
{
    std::cout << "===== testConstArray ====" << std::endl;
    int const array[] = {0, 1, 2};
    std::size_t size = 3;
    try {
        iter(&array[0], size, printer);
    }
    catch (std::exception &e)
    {
        std::cout << "printer() throws exception" << std::endl;
    }
    // iter(&array[0], size, mult); // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
}

void    testNull()
{
    std::cout << "===== test NULL ====" << std::endl;
    int const array[] = {0, 1, 2};
    std::size_t size = 3;
    void    (*func)(const int *);
    func = NULL;
    try {
        iter(&array[0], size - 1, func);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    testNormalArray();
    testConstArray();
    testNull();
}
