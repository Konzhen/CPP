#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "ClapTrap.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class ScavTrap : public ClapTrap
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
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &scavtrap);
        ~ScavTrap();


    // Operators
        ScavTrap &operator=(const ScavTrap &scavtrap);

    // Getters & Setters


    // Member Functions
        void    attack(const std::string& target);
        void    guardGate(void);

};

#endif