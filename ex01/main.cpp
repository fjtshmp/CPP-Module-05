#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 50);
		Form tax("TaxForm", 40, 20);

		std::cout << bob << std::endl;
		std::cout << tax << std::endl;

		bob.signForm(tax);
	}
	catch (std::exception &e)
	{
	std::cout << e.what() << std::endl;
	}
}
