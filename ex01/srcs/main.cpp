#include "itr.hpp"


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
    itr(&array[0], size, printer);
    itr(&array[0], size, mult);
    itr(&array[0], size, printer);
    std::cout << std::endl << std::endl << std::endl;
}

void    testConstArray()
{
    std::cout << "===== testConstArray ====" << std::endl;
    int const array[] = {0, 1, 2};
    std::size_t size = 3;
    itr(&array[0], size, printer);
    // itr(&array[0], size, mult); // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
}

void    testNull()
{
    int const array[] = {0, 1, 2};
    std::size_t size = 3;
    void    (*func)(const int *);
    func = NULL;
    itr(&array[0], size, func);
}

int main()
{
    testNormalArray();
    testConstArray();
    testNull();
}
