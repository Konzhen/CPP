#include "AForm.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

AForm::AForm(const int execGrade, const int signGrade, const std::string name) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (_signGrade > 150)
        throw AForm::GradeTooLowException();
    if (_signGrade < 1)
        throw AForm::GradeTooHighException();
    if (_execGrade > 150)
        throw AForm::GradeTooLowException();
    if (_execGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &f) : _name(f._name), _signGrade(f._signGrade), _execGrade(f._execGrade), _isSigned(f._isSigned)
{
    *this = f;
    if (_signGrade > 150)
        throw AForm::GradeTooLowException();
    if (_signGrade < 1)
        throw AForm::GradeTooHighException();
    if (_execGrade > 150)
        throw AForm::GradeTooLowException();
    if (_execGrade < 1)
        throw AForm::GradeTooHighException();

}

AForm::~AForm()
{

}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

AForm    &AForm::operator=(AForm const &f)
{
    _isSigned = f._isSigned;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

const std::string   AForm::getName() const
{
    return (_name);
}

bool                AForm::getIsSigned() const
{
    return (_isSigned);
}

int                 AForm::getSignGrade() const
{
    return (_signGrade);
}

int                 AForm::getExecGrade() const
{
    return (_execGrade);
}


//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool               AForm::beSigned(Bureaucrat const &b)
{

    if (b.getGrade() < getSignGrade())
    {
        _isSigned = true;
        return (true);
    }
    else
        throw Bureaucrat::GradeTooLowException();
    return (false);
}

bool                AForm::execute(Bureaucrat const &executor) const
{
    if (_isSigned)
    {
        if (executor.getGrade() < getExecGrade())
        {
            std::cout << executor.getName() << " executed the Form " << getName() << std::endl;
            return (true);
        }
        else
            throw Bureaucrat::GradeTooLowException();    
    }
    else
        throw AForm::NotSignedException();
    return (false);
}

std::ostream &operator<<(std::ostream &o, AForm const &f)
{
    o << f.getName() << ", is signed:" << f.getIsSigned() << ", signed grade:" << f.getSignGrade() << ", execution grade:" << f.getExecGrade();
    return (o);
}

//--------------------------------------------------------------------------//

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade Too Low Exception");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade Too High Exception");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("AForm Not Signed Exception");
}
