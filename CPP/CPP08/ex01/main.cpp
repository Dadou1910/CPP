#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "=== TEST 1: Basic Functionality ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== TEST 2: Exception Handling ===" << std::endl;
        try
        {
            sp.addNumber(42);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n=== TEST 3: Large Input ===" << std::endl;
        Span largeSpan(10000);
        std::vector<int> largeNumbers;
        for (int i = 0; i < 10000; ++i)
            largeNumbers.push_back(i * 3);

        largeSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;

        std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
