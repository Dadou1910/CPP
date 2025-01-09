#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created!" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy created!" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << "Intern assignment operator called!" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed!" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; ++j) {
                if (j != i) delete forms[j];
            }
            return forms[i];
        }
    }
    for (int i = 0; i < 3; ++i) {
        delete forms[i];
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Error: Form not found!";
}