#ifndef DOG_HPP
#define DOG_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Dog : public Animal
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //

        Brain   *_brain;

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
        Dog();
        Dog(Dog const &dog);
        ~Dog();


    // Operators
        Dog &operator=(Dog const &dog);

    // Getters & Setters
        Brain   *getBrain();

    // Member Functions
        void    makeSound() const;

};

#endif