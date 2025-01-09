#include "iter.hpp"

template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
    element += 1;
}

int main()
{
    std::cout << "=== TEST 1: INT ARRAY ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    int intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incremented: ";
    iter(intArray, intLen, incrementElement<int>);
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "\n=== TEST 2: STRING ARRAY ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "42"};
    int strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\n=== TEST 3: DOUBLE ARRAY ===" << std::endl;
    double doubleArray[] = {3.14, 1.618, 2.71};
    int doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original: ";
    iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl;

    std::cout << "Incremented: ";
    iter(doubleArray, doubleLen, incrementElement<double>);
    iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl;

    return 0;
}

