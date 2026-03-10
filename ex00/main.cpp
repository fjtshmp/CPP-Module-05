#include "Bureaucrat.hpp"
#include <iostream>

static void section(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n";
}

int main()
{
	section("Valid construction");
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;

		Bureaucrat b;
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	section("Invalid construction (too high)");
	try
	{
		Bureaucrat x("X", 0);
		std::cout << x << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	section("Invalid construction (too low)");
	try
	{
		Bureaucrat y("Y", 151);
		std::cout << y << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	section("Increment / Decrement boundaries");
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		std::cout << "Try increment (should throw)..." << std::endl;
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 150);
		std::cout << low << std::endl;
		std::cout << "Try decrement (should throw)..." << std::endl;
		low.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	section("Normal grade changes");
	try
	{
		Bureaucrat c("Carol", 3);
		std::cout << c << std::endl;

		c.incrementGrade();
		std::cout << "after increment: " << c << std::endl;

		c.decrementGrade();
		std::cout << "after decrement: " << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	section("Copy & assignment (note: name is const)");
	try
	{
		Bureaucrat a("A", 10);
		Bureaucrat b("B", 140);

		Bureaucrat c(a); // copy ctor copies name+grade
		std::cout << "c(copy of a): " << c << std::endl;

		std::cout << "before b=a: " << b << std::endl;
		b = a; // assignment copies grade only, keeps b's name
		std::cout << "after  b=a: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return 0;
}
