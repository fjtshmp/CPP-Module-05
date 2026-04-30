#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "===== Intern makeForm test =====" << std::endl;

    Intern intern;

    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    AForm* form2 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* form3 = intern.makeForm("shrubbery creation", "Home");
    AForm* form4 = intern.makeForm("unknown form", "Nobody");

    std::cout << std::endl;

    Bureaucrat boss("Boss", 1);

    try {
        if (form1) {
            std::cout << *form1 << std::endl;
            boss.signForm(*form1);
            boss.executeForm(*form1);
        }

        std::cout << std::endl;

        if (form2) {
            std::cout << *form2 << std::endl;
            boss.signForm(*form2);
            boss.executeForm(*form2);
        }

        std::cout << std::endl;

        if (form3) {
            std::cout << *form3 << std::endl;
            boss.signForm(*form3);
            boss.executeForm(*form3);
        }

        std::cout << std::endl;

        if (form4) {
            std::cout << *form4 << std::endl;
            boss.signForm(*form4);
            boss.executeForm(*form4);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
