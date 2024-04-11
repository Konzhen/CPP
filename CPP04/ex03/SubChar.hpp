#ifndef SUBCHAR_HPP
#define SUBCHAR_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class SubChar : public ICharacter
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
        SubChar(std::string const name);
        SubChar(SubChar const &subchar);
        ~SubChar();


    // Operators
        SubChar &operator=(SubChar const &subchar);

    // Getters & Setters
        std::string const &getName() const;
        AMateria *getMateria(int idx) const;

    // Member Functions
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void trololo();
};

#endif