#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "===TEST 1===\nCreating Bureaucrats" << std::endl;
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        
        std::cout << "\n===TEST 2===\nTesting ShrubberyCreationForm" << std::endl;
        ShrubberyCreationForm shrubbery("HomeGarden");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        std::cout << "\n===TEST 3===\nTesting RobotomyRequestForm" << std::endl;
        RobotomyRequestForm robotomy("AliceBot");
        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        std::cout << "\n===TEST 4===\nTesting PresidentialPardonForm" << std::endl;
        PresidentialPardonForm pardon("Bob's Mistake");
        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n===TEST 5===\nTesting execution with low-grade Bureaucrat" << std::endl;
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        std::cout << "\n===TEST 6===\nTesting increment and decrement of grades" << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.decrementGrade();
        std::cout << alice << std::endl;

        std::cout << "\n===TEST 7===\nTesting invalid grade (too high)" << std::endl;
        Bureaucrat john("John", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n===TEST 8===\nTesting invalid grade (too low)" << std::endl;
        Bureaucrat jane("Jane", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
