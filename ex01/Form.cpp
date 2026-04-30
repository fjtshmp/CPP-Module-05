#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("default"),
      _is_signed(false),
      _grade_to_sign(150),
      _grade_to_execute(150) {}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {
    if (_grade_to_sign < 1 || _grade_to_execute < 1) {
        throw Form::GradeTooHighException();
    }
    if (_grade_to_sign > 150 || _grade_to_execute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : _name(other._name),
      _is_signed(other._is_signed),
      _grade_to_sign(other._grade_to_sign),
      _grade_to_execute(other._grade_to_execute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_is_signed = other._is_signed;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _is_signed;
}

int Form::getGradeToSign() const {
    return _grade_to_sign;
}

int Form::getGradeToExecute() const {
    return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _grade_to_sign) {
        throw Form::GradeTooLowException();
    }
    _is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form name: " << form.getName()
       << ", signed: " << (form.getIsSigned() ? "true" : "false")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
