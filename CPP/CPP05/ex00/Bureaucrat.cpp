#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : Name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : Name(other.Name), Grade(other.Grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        Grade = other.Grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return Name; }
int Bureaucrat::getGrade() const { return Grade; }

void Bureaucrat::incrementGrade()
{
    Grade--;
    if (Grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    Grade++;
    if (Grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
