#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : Name(name), IsSigned(false), GradeToSign(gradeToSign), GradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

std::string Form::getName() const { return Name; }
bool Form::getIsSigned() const { return IsSigned; }
int Form::getGradeToSign() const { return GradeToSign; }
int Form::getGradeToExecute() const { return GradeToExecute; }

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw GradeTooLowException();
    IsSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName()
        << " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << " | Grade to Sign: " << form.getGradeToSign()
        << " | Grade to Execute: " << form.getGradeToExecute();
    return out;
}


