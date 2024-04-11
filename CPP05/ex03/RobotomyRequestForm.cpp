#include "RobotomyRequestForm.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

RobotomyRequestForm::RobotomyRequestForm(const std::string name, std::string target) : AForm(45, 72, name), _target(target)
{
    std::cout << "Robotomy Request form: " << getName() << " as been adopted, Sign grade: " << getSignGrade() << ", Exec grade:" << getExecGrade() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyrequestform) : AForm(robotomyrequestform)
{
    *this = robotomyrequestform;
    std::cout << "Robotomy Request form: " << getName() << " as been copied." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Request form: " << getName() << " as been dismissed." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

RobotomyRequestForm    &RobotomyRequestForm::operator=(RobotomyRequestForm const &f)
{
    _target = f._target;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string         RobotomyRequestForm::getTarget() const
{
    return _target;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool                RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (getIsSigned())
    {
        if (executor.getGrade() < getExecGrade())
        {
            std::cout << "Driiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiing" << std::endl;
            std::srand(std::time(0));
            if (std::rand() % 2)
                std::cout << _target << ": has been robotomized" << std::endl;
            else
                std::cout << _target << ": robotomy failed" << std::endl;
            return (true);
        }
        else
            throw Bureaucrat::GradeTooLowException(); 
    }
    else
        throw AForm::NotSignedException();
    return (false);
}
