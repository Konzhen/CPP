#include "Form.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Form::Form(const int execGrade, const int signGrade, const std::string name) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (_signGrade > 150)
        throw Form::GradeTooLowException();
    if (_signGrade < 1)
        throw Form::GradeTooHighException();
    if (_execGrade > 150)
        throw Form::GradeTooLowException();
    if (_execGrade < 1)
        throw Form::GradeTooHighException();
    std::cout << _name << " Form as been adopted" << std::endl;
}

Form::Form(Form const &form) : _name(form._name), _signGrade(form._signGrade), _execGrade(form._execGrade), _isSigned(form._isSigned)
{
    *this = form;
    if (_signGrade > 150)
        throw Form::GradeTooLowException();
    if (_signGrade < 1)
        throw Form::GradeTooHighException();
    if (_execGrade > 150)
        throw Form::GradeTooLowException();
    if (_execGrade < 1)
        throw Form::GradeTooHighException();
    std::cout << _name << " Form as been adopted" << std::endl;
}

Form::~Form()
{
    std::cout << getName() << " Form as been dismissed" << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Form    &Form::operator=(Form const &form)
{
    _isSigned = form._isSigned;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

const std::string   Form::getName() const
{
    return (_name);
}

bool                Form::getIsSigned() const
{
    return (_isSigned);
}

int                 Form::getSignGrade() const
{
    return (_signGrade);
}

int                 Form::getExecGrade() const
{
    return (_execGrade);
}


//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool               Form::beSigned(Bureaucrat const &b)
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



std::ostream &operator<<(std::ostream &o, Form const &form)
{
    o << form.getName() << ", is signed:" << form.getIsSigned() << ", signed grade:" << form.getSignGrade() << ", execution grade:" << form.getExecGrade();
    return (o);
}

//--------------------------------------------------------------------------//

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade Too Low Exception");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade Too High Exception");
}
