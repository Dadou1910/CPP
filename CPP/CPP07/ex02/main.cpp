#include "Array.hpp"

#define MAX_VAL 750

int main()
{
    std::cout << "=== TEST 1: Basic Functionality ===" << std::endl;

    Array<int> defaultArray;
    std::cout << "Default array size: " << defaultArray.getSize() << std::endl;

    Array<int> paramArray(5);
    std::cout << "Parameterized array size: " << paramArray.getSize() << std::endl;

    for (unsigned int i = 0; i < paramArray.getSize(); i++)
        paramArray[i] = i * 10;

    std::cout << "Values in parameterized array: ";
    for (unsigned int i = 0; i < paramArray.getSize(); i++)
        std::cout << paramArray[i] << " ";
    std::cout << std::endl;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "\n=== TEST 2: Copy and Assignment ===" << std::endl;

    Array<int> copy = numbers;
    Array<int> assigned(10);
    assigned = numbers;

    std::cout << "Original size: " << numbers.getSize() << std::endl;
    std::cout << "Copy size: " << copy.getSize() << std::endl;
    std::cout << "Assigned size: " << assigned.getSize() << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != copy[i] || numbers[i] != assigned[i])
        {
            std::cerr << "Error: Copy or assignment failed at index " << i << std::endl;
            return 1;
        }
    }

    std::cout << "\n=== TEST 3: Out-of-Bounds Access ===" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Deep Copy Verification ===" << std::endl;

    numbers[0] = 42;
    std::cout << "Modified numbers[0]: " << numbers[0] << std::endl;
    std::cout << "Copy numbers[0]: " << copy[0] << " (should be unchanged)" << std::endl;

    std::cout << "\n=== TEST 5: Size Function ===" << std::endl;
    std::cout << "Size of numbers array: " << numbers.getSize() << std::endl;
    std::cout << "Size of assigned array: " << assigned.getSize() << std::endl;

    std::cout << "\n=== TEST 6: Empty Array ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.getSize() << std::endl;
    try
    {
        emptyArray[0] = 10;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete[] mirror;
    std::cout << "\n=== All tests completed successfully! ===" << std::endl;

    return 0;
}
