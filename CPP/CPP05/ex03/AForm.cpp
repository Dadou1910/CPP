#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : Name(name), IsSigned(false), GradeToSign(gradeToSign), GradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : Name(other.Name), IsSigned(other.IsSigned), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        IsSigned = other.IsSigned;
    return *this;
}

std::string AForm::getName() const { return Name; }
bool AForm::getIsSigned() const { return IsSigned; }
int AForm::getGradeToSign() const { return GradeToSign; }
int AForm::getGradeToExecute() const { return GradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw GradeTooLowException();
    IsSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low!"; }
const char *AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: " << form.getName() << ", Signed: " << form.getIsSigned() 
        << ", Grade to Sign: " << form.getGradeToSign() 
        << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}