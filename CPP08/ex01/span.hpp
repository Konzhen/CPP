 #ifndef SPAN_HPP
#define SPAN_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <time.h>
# include <stdlib.h>

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class Span
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        unsigned int                _maxN;
        std::vector<int>            _v;
        std::vector<int>::iterator  _min;
        std::vector<int>::iterator  _max;


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
        Span(unsigned int n);
        Span(unsigned int n, int max);
        Span(Span const &span);
        ~Span();


    // Operators
        Span &operator=(const Span &span);

    // Getters & Setters
        std::vector<int> getVector() const;
        unsigned int     getMaxN() const;

    // Member Functions
        void printAll();
        void addNumber(int n);
        int  shortestSpan();
        int  longestSpan();

};

#endif