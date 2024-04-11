#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Bernard", 50);
		std::cout << std::endl;
		a++;
		std::cout << a << std::endl;
		a++;
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl;
	try
	{
		Bureaucrat b("Jean", 2);
		std::cout << std::endl;
		b++;
		std::cout << b << std::endl;
		b++;
		std::cout << b << std::endl;
		b.addGrade(30);
		std::cout << b << std::endl;
		b.lowerGrade(30);
		std::cout << b << std::endl;
		b.addGrade(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl;
	try
	{
		Bureaucrat c("Wang", 149);
		std::cout << std::endl;
		c--;
		std::cout << c << std::endl;
		c--;
		std::cout << c << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl;
	try
	{
		Bureaucrat d("Yvan", 0);
		std::cout << d << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl;
	try
	{
		Bureaucrat e("Navy", 151);
		std::cout << e << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat f("Alex", 50);
		std::cout << std::endl;
		f.addGrade(30);
		std::cout << f << std::endl;
		f.lowerGrade(30);
		std::cout << f << std::endl;
		f.addGrade(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}