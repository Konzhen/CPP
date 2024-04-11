#ifndef CAT_HPP
#define CAT_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Cat : public Animal
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
        Cat();
        Cat(Cat const &cat);
        ~Cat();


    // Operators
        Cat &operator=(Cat const &cat);

    // Getters & Setters
        Brain   *getBrain();

    // Member Functions
        void    makeSound() const;

};

#endif