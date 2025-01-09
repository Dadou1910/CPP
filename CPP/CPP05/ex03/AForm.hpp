#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string Name;
    bool IsSigned;
    const int GradeToSign;
    const int GradeToExecute;

public:
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif

