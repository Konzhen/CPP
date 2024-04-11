#ifndef CHARACTER_HPP
#define CHARACTER_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Character : public ICharacter
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //

        std::string     _name;
        AMateria        *_inventory[4];

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
        Character(std::string const name);
        Character(Character const &character);
        ~Character();


    // Operators
        Character &operator=(Character const &character);

    // Getters & Setters
        std::string const &getName() const;
        AMateria *getMateria(int idx) const;

    // Member Functions
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif