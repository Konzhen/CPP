#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib>
# include <ctime>


//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class RobotomyRequestForm : public AForm
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        std::string _target;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        RobotomyRequestForm();

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
        RobotomyRequestForm(const std::string name, std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &robotomyrequestform);
        ~RobotomyRequestForm();


    // Operators
        RobotomyRequestForm &operator=(RobotomyRequestForm const &f);

    // Getters & Setters
        std::string         getTarget() const;

    // Member Functions
        bool                execute(Bureaucrat const &executor) const;

};

#endif