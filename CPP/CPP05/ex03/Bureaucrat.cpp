#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : Name(name), Grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : Name(other.Name), Grade(other.Grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        Grade = other.Grade;
    return *this;
}

std::string Bureaucrat::getName() const { return Name; }
int Bureaucrat::getGrade() const { return Grade; }

void Bureaucrat::incrementGrade()
{
    if (Grade <= 1)
        throw GradeTooHighException();
    --Grade;
}

void Bureaucrat::decrementGrade()
{
    if (Grade >= 150)
        throw GradeTooLowException();
    ++Grade;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << Name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << Name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << Name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << Name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low!"; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
