#include "Intern.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Intern::Intern()
{

}

Intern::Intern(Intern const &intern)
{
    (void)intern;
}

Intern::~Intern()
{

}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Intern    &Intern::operator=(Intern const &intern)
{
    (void)intern;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//



AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string	input[] = 
    {
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};

    int i;

    for (i = 0; i < 3; i++)
    {
        if (input[i] == name)
            break ;
    }

    AForm *form;

    switch (i)
    {
        case 0:
        {
            form = new PresidentialPardonForm(name, target);
            break ;
        }
        case 1:
        {
            form = new RobotomyRequestForm(name, target);
            break ;
        }
        case 2:
        {
            form = new ShrubberyCreationForm(name, target);
            break ;
        }
        default:
            throw std::runtime_error("Error: This form type doesn' t exist.");
    }
    
    std::cout << "Intern creates " << form->getName() << std::endl;
    return (form);
}
