#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("b1", 50);
		Bureaucrat b2("b2", 5);
		Bureaucrat b3("b3", 100);
		Form f1(30, 55, "f1");

		std::cout << std::endl;

		std::cout << f1 << std::endl;
		std::cout << b3 << std::endl;
		b3.signForm(f1);

		std::cout << std::endl;

		std::cout << b2 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat b1("b1", 50);
		Form f1(30, 55, "f1");		
		Form *f2 = new Form(f1);
		std::cout << "(f2)" << *f2 << std::endl;
		delete(f2);

		std::cout << std::endl;

		Form f3(1, 18, "f3");
		std::cout << f3 << std::endl;
		std::cout << b1 << std::endl;
		b1++;
		std::cout << b1 << std::endl;
		b1++;
		std::cout << b1 << std::endl;
		b1++;
		std::cout << b1 << std::endl;
		b1--;
		std::cout << b1 << std::endl;

		std::cout << std::endl;
		
		b1.signForm(f3);
		b1.lowerGrade(67);
		std::cout << b1 << std::endl;
		b1.lowerGrade(98);
		std::cout << b1 << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat b1("b1", 50);
		Bureaucrat b2(b1);
		Form f1(30, 55, "f1");		
		Form f3(1, 18, "f3");
		std::cout << f3 << std::endl;
		std::cout << "(b2)" << b2 << std::endl;
	
		std::cout << std::endl;

		std::cout << b1 << std::endl;
		b1++;
		b1++;
		b1++;
		std::cout << b1 << std::endl;
		b1.signForm(f3);

		std::cout << std::endl;

		b1.lowerGrade(67);
		std::cout << b1 << std::endl;
		b1.addGrade(98);
		std::cout << b1 << std::endl;
		b1.signForm(f3);

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

try
	{
		Bureaucrat b1("b1", 143);	
		Form f1(1, 18, "f1");
		std::cout << f1 << std::endl;
	
		std::cout << std::endl;

		b1.lowerGrade(67);
		std::cout << b1 << std::endl;
		b1.addGrade(98);
		std::cout << b1 << std::endl;
		b1.signForm(f1);

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

try
	{
		Bureaucrat b1("b1", 151);	
		std::cout << b1 << std::endl;
	
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

try
	{
		Bureaucrat b1("b1", 20);
		Form f1(10, 30, "f1");
		b1.signForm(f1);
		std::cout << b1 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
}