#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "===TEST 1===" << std::endl;
        Bureaucrat b1("Alice", 5);
        Form f1("Important Form", 10, 20);
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << "\n===TEST 2===" << std::endl;
        Bureaucrat b2("Bob", 50);
        Form f2("Restricted Form", 20, 30);
        std::cout << f2 << std::endl;

        b2.signForm(f2);
        std::cout << f2 << std::endl;

        std::cout << "\n===TEST 3===" << std::endl;
        Form f3("Invalid Form", 0, 20);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
