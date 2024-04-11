#ifndef AMATERIA_HPP
#define AMATERIA_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "ICharacter.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class ICharacter;

class AMateria
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

        std::string _type;

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
        AMateria(std::string const &type);
        AMateria(AMateria const &amateria);
        virtual ~AMateria();


    // Operators
        AMateria &operator=(AMateria const &amateria);

    // Getters & Setters
        std::string const   &getType() const;
        void                setType(std::string type);

    // Member Functions
        virtual AMateria    *clone() const = 0;
        virtual void        use(ICharacter& target);

};

#endif