#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class ShrubberyCreationForm : public AForm
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        std::string _target;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        ShrubberyCreationForm();

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
        ShrubberyCreationForm(const std::string name, std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &shrubberycreationform);
        ~ShrubberyCreationForm();


    // Operators
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &f);

    // Getters & Setters
        std::string         getTarget() const;

    // Member Functions
        bool                execute(Bureaucrat const &executor) const;

};

#endif