#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    friend std::ostream &operator<<(std::ostream &out, const Form &form);
};

#endif
