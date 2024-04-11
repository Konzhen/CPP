#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class MateriaSource : public IMateriaSource
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        AMateria        *_memory[4];


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
        MateriaSource();
        MateriaSource(MateriaSource const &materiasource);
        ~MateriaSource();


    // Operators
        MateriaSource &operator=(MateriaSource const &materiasource);

    // Getters & Setters


    // Member Functions
		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const & type);

};

#endif