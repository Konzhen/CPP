#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "ClapTrap.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class FragTrap : public ClapTrap
{
//--PRIVATE-----------------------------------------------------------------//
    private:
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
        FragTrap(std::string name);
        FragTrap(FragTrap const &fragtrap);
        ~FragTrap();


    // Operators
        FragTrap &operator=(const FragTrap &fragtrap);

    // Getters & Setters


    // Member Functions
        void    highFivesGuys(void);

};

#endif