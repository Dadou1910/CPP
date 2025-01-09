#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "(test : grade of Bob = 151)" << std::endl;
        Bureaucrat b("Bob", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "(test : grade of Charlie = 0)" << std::endl;
        Bureaucrat c("Charlie", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}