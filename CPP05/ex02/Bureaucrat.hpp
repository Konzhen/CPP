#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AForm.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class AForm;

class Bureaucrat
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        std::string const   _name;
        int                 _grade;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        Bureaucrat();

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
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &bureaucrat);
        ~Bureaucrat();


    // Operators
        Bureaucrat &operator=(Bureaucrat const &bureaucrat);
        Bureaucrat &operator++(int);
        Bureaucrat &operator--(int);

    // Getters & Setters
        const std::string   getName() const;
        int                 getGrade() const;

    // Member Functions

        void                addGrade(int const g);
        void                lowerGrade(int const g);
        void                signForm(AForm &f) const;
        void                executeForm(AForm const &aform);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif