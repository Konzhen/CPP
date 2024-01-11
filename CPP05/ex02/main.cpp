#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	AForm *f1 = new PresidentialPardonForm("f1", "Dock");
	AForm *f2 = new ShrubberyCreationForm("f2", "Dick");
	AForm *f3 = new RobotomyRequestForm("f3", "Dack");
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 1);
		Bureaucrat b3("b3", 50);
		b1.signForm(*f1);
		b2.executeForm(*f1);
		b1.signForm(*f2);
		b2.executeForm(*f2);
		b1.signForm(*f3);
		b2.executeForm(*f3);
		b3.signForm(*f3);
		b3.executeForm(*f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete(f1);
	delete(f2);
	delete(f3);
}