#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include <stdint.h>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Data;

class Serializer
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //


                           // - FUNCTIONS - //

    // Constructor & Destructors
        Serializer();
        Serializer(Serializer const &serializer);

    // Operators
        Serializer &operator=(Serializer const &serializer);

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
        ~Serializer();


    // Operators


    // Getters & Setters


    // Member Functions
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

};

#endif