#ifndef CURE_HPP
#define CURE_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "SubChar.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Cure : public AMateria
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors


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
        Cure();
        Cure(Cure const &cure);
        ~Cure();


    // Operators
        Cure &operator=(Cure const &cure);

    // Getters & Setters


    // Member Functions
        AMateria    *clone() const;
        void        use(ICharacter& target);
        void        heal(SubChar *s);

};

#endif