 #ifndef SPAN_HPP
#define SPAN_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class Span
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        unsigned int    _n;


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
        Span();
        Span(Span &span);
        ~Span();


    // Operators
        Span &operator=(const Span &span);

    // Getters & Setters


    // Member Functions


};

#endif