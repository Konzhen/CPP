#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	AForm *f1 = new PresidentialPardonForm("f1", "Basilic");
	AForm *f2 = new ShrubberyCreationForm("f2", "Menthe");
	AForm *f3 = new RobotomyRequestForm("f3", "Ciboulette");
	try
	{
		Bureaucrat b1("Capricorne", 1);
		Bureaucrat b2("Belier", 1);
		Bureaucrat b3("Cancer", 50);

		std::cout << std::endl;

		b1.signForm(*f1);
		b2.executeForm(*f1);

		std::cout << std::endl;

		b1.signForm(*f2);
		b2.executeForm(*f2);

		std::cout << std::endl;

		b1.signForm(*f3);
		b2.executeForm(*f3);

		std::cout << std::endl;

		b3.signForm(*f3);
		b3.executeForm(*f3);

		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete(f1);
	delete(f2);
	delete(f3);
}