#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));
	std::cout<<std::time(NULL)<<std::endl;

    Bureaucrat high("Alice", 1);
    Bureaucrat middle("Bob", 50);
    Bureaucrat low("Charlie", 150);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << "\n--- Form info ---" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- Execute unsigned form ---" << std::endl;
    high.executeForm(shrubbery);

    std::cout << "\n--- Sign forms ---" << std::endl;
    low.signForm(shrubbery);
	middle.signForm(shrubbery);
    middle.signForm(robotomy);
    high.signForm(pardon);

    std::cout << "\n--- Execute forms ---" << std::endl;
    middle.executeForm(shrubbery);
    middle.executeForm(robotomy);
    middle.executeForm(pardon);

    std::cout << "\n--- Execute with high grade bureaucrat ---" << std::endl;
    high.executeForm(shrubbery);
    high.executeForm(robotomy);
    high.executeForm(pardon);

    return 0;
}
