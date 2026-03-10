#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute)
: name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if(grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if(grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
: name(other.name),
  is_signed(other.is_signed),
  grade_to_sign(other.grade_to_sign),
  grade_to_execute(other.grade_to_execute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

Form::~Form(){}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return is_signed;
}

int Form::getGradeToSign() const
{
    return grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return grade_to_execute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName()
        << ", signed: " << form.getIsSigned()
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
