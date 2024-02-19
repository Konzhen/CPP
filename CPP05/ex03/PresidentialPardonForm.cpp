#include "PresidentialPardonForm.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

PresidentialPardonForm::PresidentialPardonForm(const std::string name, std::string target) : AForm(5, 25, name), _target(target)
{
    std::cout << "Presidential pardon form: " << getName() << " as been adopted, Sign grade: " << getSignGrade() << ", Exec grade:" << getExecGrade() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialpardonform) : AForm(presidentialpardonform)
{
    *this = presidentialpardonform;
    std::cout << "Presidential pardon form: " << getName() << " as been copied." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential pardon form: " << getName() << " as been dismissed." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

PresidentialPardonForm    &PresidentialPardonForm::operator=(PresidentialPardonForm const &f)
{
    _target = f._target;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string         PresidentialPardonForm::getTarget() const
{
    return _target;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool                PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (getIsSigned())
    {
        if (executor.getGrade() < getExecGrade())
        {
            std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
            return (true);
        }
        else
            throw Bureaucrat::GradeTooLowException(); 
    }
    else
        throw AForm::NotSignedException();
    return (false);
}
