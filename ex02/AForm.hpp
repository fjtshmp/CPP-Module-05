#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int exec_grade;

protected:
    std::string target;

public:
    AForm(std::string name, int sign, int exec, std::string target);
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &b);

    void execute(Bureaucrat const & executor) const;

    virtual void executeAction() const = 0;

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
};

#endif
