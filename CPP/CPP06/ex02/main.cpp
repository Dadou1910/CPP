#include "Identify.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Generate and Identify by Pointer ===" << std::endl;
    Base *obj1 = generate();
    identify(obj1);

    std::cout << "=== TEST 2: Generate and Identify by Reference ===" << std::endl;
    Base &obj2 = *generate();
    identify(obj2);

    std::cout << "=== TEST 3: Random Tests ===" << std::endl;
    Base *randomObj;
    for (int i = 0; i < 5; ++i)
    {
        randomObj = generate();
        identify(randomObj);
        identify(*randomObj);
        delete randomObj;
    }

    return 0;
}

