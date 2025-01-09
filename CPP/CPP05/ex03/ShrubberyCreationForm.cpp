#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), Target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), Target(other.Target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        Target = other.Target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((Target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Failed to create file!");

    file << "     ^^^     \n"
         << "    ^^^^^    \n"
         << "   ^^^^^^^   \n"
         << "  ^^^^^^^^^  \n"
         << " ^^^^^^^^^^^ \n"
         << "      ||     \n";

    file.close();
}
