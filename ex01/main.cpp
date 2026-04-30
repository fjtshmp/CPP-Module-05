#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 50);
		Form tax_a("TaxForm", 40, 20);
		Form tax_b("TaxForm_b",100,50);

		std::cout << bob << std::endl;
		std::cout << tax_a << std::endl;
		std::cout << tax_b << std::endl;

		bob.signForm(tax_a);
		bob.signForm(tax_b);
	}
	catch (std::exception &e)
	{
	std::cout << e.what() << std::endl;
	}
}
