#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string n, int s, int e, std::string t)
: name(n), is_signed(false), sign_grade(s), exec_grade(e), target(t)
{
}

AForm::~AForm(){}

std::string AForm::getName() const { return name; }
bool AForm::getSigned() const { return is_signed; }
int AForm::getSignGrade() const { return sign_grade; }
int AForm::getExecGrade() const { return exec_grade; }

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > sign_grade)
        throw GradeTooLowException();
    is_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if(!is_signed)
		throw FormNotSignedException();

	if(executor.getGrade() > exec_grade)
		throw GradeTooLowException();

	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}
