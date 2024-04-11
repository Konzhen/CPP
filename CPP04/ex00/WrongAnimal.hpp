#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class WrongAnimal
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
        WrongAnimal();
        WrongAnimal(WrongAnimal const &WrongAnimal);
        ~WrongAnimal();

    // Operators
        WrongAnimal &operator=(WrongAnimal const &WrongAnimal);

    // Getters & Setters
        std::string getType() const;
        void        setType(std::string type);

    // Member Functions
        void        makeSound() const;

};

#endif