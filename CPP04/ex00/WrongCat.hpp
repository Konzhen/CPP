#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "WrongAnimal.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class WrongCat : public WrongAnimal
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
        WrongCat();
        WrongCat(WrongCat const &wrongCat);
        ~WrongCat();


    // Operators
        WrongCat &operator=(WrongCat const &wrongCat);

    // Getters & Setters


    // Member Functions
        void    makeSound() const;

};

#endif