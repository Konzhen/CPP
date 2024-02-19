#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Intern intern;

		AForm *form = intern.makeForm("Presidential Pardon", "Ennuie");
		delete(form);
		std::cout << std::endl;
		form = intern.makeForm("Shrubbery Creation", "Chenille");
		delete(form);
		std::cout << std::endl;
		form = intern.makeForm("Robotomy Request", "Bahamut");
		delete(form);
		std::cout << std::endl;

		intern.makeForm("YOLO", "Douda");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;

	try
	{
		Intern intern;

		AForm *form = intern.makeForm("Presidential Pardonn", "Pouet");
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}