#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class PresidentialPardonForm : public AForm
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        std::string _target;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        PresidentialPardonForm();

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
        PresidentialPardonForm(const std::string name, std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &presidentialpardonform);
        ~PresidentialPardonForm();


    // Operators
        PresidentialPardonForm &operator=(PresidentialPardonForm const &f);

    // Getters & Setters
        std::string         getTarget() const;

    // Member Functions
        bool                execute(Bureaucrat const &executor) const;

};

#endif