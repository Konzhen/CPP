 #ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>


//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

template <typename T>
class MutantStack : public std::stack<T>
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



                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions


//--PUBLIC------------------------------------------------------------------//
    public:
                           // - VARIABLES - //
        typedef T   *iter;


                           // - FUNCTIONS - //

    // Constructor & Destructors
        MutantStack();
        MutantStack(MutantStack &mutantstack)
        {
            *this = mutantstack;
        }
        ~MutantStack();


    // Operators
        MutantStack &operator=(const MutantStack &mutantstack)
        {
            iter = mutantstack.iter;
            return *this;
        }

    // Getters & Setters


    // Member Functions
        iter    begin()
        {
            return c[0];
        }

        iter    end()
        {
            return c.top() + 1;
        }

};

#endif