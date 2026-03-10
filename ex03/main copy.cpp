#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm s("home");
    RobotomyRequestForm r("Bender");
    PresidentialPardonForm p("Marvin");

    s.beSigned(bob);
    r.beSigned(bob);
    p.beSigned(bob);

    bob.executeForm(s);
    bob.executeForm(r);
    bob.executeForm(p);
}
