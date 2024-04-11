#include "Bureaucrat.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "New employee joined our company! Say welcome to " << _name << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat._name)
{
    *this = bureaucrat;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "New employee joined our company! Say welcome to " << _name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "An employee left our company... again." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Bureaucrat    &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
    _grade = bureaucrat._grade;
    return (*this);
}

Bureaucrat    &Bureaucrat::operator++(int)
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    return (*this);
}

Bureaucrat    &Bureaucrat::operator--(int)
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    return (*this);
}



//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

const std::string  Bureaucrat::getName() const
{
    return (_name);
}

int         Bureaucrat::getGrade() const
{
    return (_grade);
}


//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void                Bureaucrat::addGrade(int const g)
{
    if (_grade - g < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= g;
}

void                Bureaucrat::lowerGrade(int const g)
{
    if (_grade + g > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += g;
}

void                Bureaucrat::signForm(Form &f) const
{
    try
    {
        if (f.beSigned(*this))
            std::cout << getName() << ", signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << ", could't sign " << f.getName() << " because " << e.what() << '\n';
        throw Bureaucrat::GradeTooLowException();
    }
}

//--------------------------------------------------------------------------//

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade Too Low Exception");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade Too High Exception");
}


std::ostream    &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (o);
}