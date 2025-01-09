#include "easyfind.hpp"

int main()
{
    std::cout << "=== TEST 1: Vector ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 8);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: List ===" << std::endl;
    std::list<int> lst;
    for (int i = 10; i > 0; --i)
        lst.push_back(i);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Empty Container ===" << std::endl;
    std::vector<int> empty;

    try
    {
        std::vector<int>::iterator it = easyfind(empty, 1);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
