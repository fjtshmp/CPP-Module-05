#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    delete f1;

    AForm* f2 = intern.makeForm("shrubbery creation", "Home");
    delete f2;

    AForm* f3 = intern.makeForm("unknown form", "target");
    delete f3;
}
