#ifndef AFORM_HPP
#define AFORM_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "Bureaucrat.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Bureaucrat;

class Form
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _isSigned;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        Form();

    // Operators


    // Getters & Setters


    // Member Functions


//--PROTECTED---------------------------------------------------------------//
    protected:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions


//--PUBLIC------------------------------------------------------------------//
    public:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors
        Form(const int execGrade, const int signGrade, const std::string name);
        Form(Form const &form);
        ~Form();


    // Operators
        Form &operator=(Form const &form);

    // Getters & Setters
        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getExecGrade() const;
        int                 getSignGrade() const;

    // Member Functions

        bool                beSigned(Bureaucrat const &b);

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream &operator<<(std::ostream &o, Form const &form);


#endif