#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== TEST 1: Basic Functionality ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n=== TEST 2: Iterator Support ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Elements in MutantStack: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST 3: Reverse Iterator ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "Reverse order: ";
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST 4: Copy and Assignment ===" << std::endl;
    MutantStack<int> copyStack = mstack;
    std::cout << "Copy size: " << copyStack.size() << std::endl;

    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned size: " << assignedStack.size() << std::endl;

    std::cout << "\n=== TEST 5: Comparison with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Elements in std::list: ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
    {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    return 0;
}
