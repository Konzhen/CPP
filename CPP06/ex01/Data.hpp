#ifndef DATA_HPP
#define DATA_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Data
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //


                           // - FUNCTIONS - //

    // Constructor & Destructors
        Data(Data const &data);

    // Operators
        Data &operator=(Data const &data);

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
        int a;
        int b;
        int c;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        Data();
        ~Data();


    // Operators

    // Getters & Setters


    // Member Functions


};

#endif