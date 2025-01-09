#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Intern intern;

        AForm *form1 = intern.makeForm("shrubbery creation", "Garden");
        AForm *form2 = intern.makeForm("robotomy request", "Bender");
        AForm *form3 = intern.makeForm("presidential pardon", "Zaphod");

        Bureaucrat boss("Boss", 1);

        boss.signForm(*form1);
        boss.executeForm(*form1);

        boss.signForm(*form2);
        boss.executeForm(*form2);

        boss.signForm(*form3);
        boss.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;

        AForm *invalid = intern.makeForm("invalid form", "Test");
        delete invalid;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

