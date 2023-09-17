#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750

int pdfTest()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "same value check OK" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

int main()
{
    std::cout << "============ test int ==============" << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i;
        std::cout << intArray[i] << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test string ==============" << std::endl;
    Array<std::string> strArray(5);
    for (unsigned int i = 0; i < strArray.size(); i++)
    {
        strArray[i] = std::to_string(i);
        std::cout << strArray[i] << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test copy ==============" << std::endl;
    Array<std::string> strArray2(strArray);
    for (unsigned int i = 0; i < strArray2.size(); i++)
    {
        std::cout << strArray2[i] << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test assign ==============" << std::endl;
    Array<std::string> strArray3 = strArray;
    for (unsigned int i = 0; i < strArray3.size(); i++)
    {
        std::cout << strArray3[i] << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test exception ==============" << std::endl;
    try
    {
        std::cout << strArray3[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test pdf ==============" << std::endl;
    pdfTest();
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "============ test empty ==============" << std::endl;
    Array<std::string> strArray4;
    std::cout << strArray4.size() << std::endl;
    std::cout << std::endl << std::endl << std::endl;

    return (0);
}