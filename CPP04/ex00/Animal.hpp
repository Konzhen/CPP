#ifndef ANIMAL_HPP
#define ANIMAL_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Animal
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
        Animal();
        Animal(Animal const &animal);
        virtual ~Animal();


    // Operators
        Animal &operator=(Animal const &animal);

    // Getters & Setters
        std::string     getType() const;
        void            setType(std::string type);

    // Member Functions
        virtual void    makeSound() const;

};

#endif