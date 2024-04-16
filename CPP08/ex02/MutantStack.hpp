#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>
# include <stack>

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


                           // - FUNCTIONS - //

    // Constructor & Destructors
        MutantStack<T>() {}
        MutantStack<T>(MutantStack &mut) : std::stack<T>(mut)
        {
            *this = mut;
        }
        ~MutantStack<T>() {}


    // Operators
        MutantStack<T> &operator=(const MutantStack<T> &mut)
        {
            *this = mut;
            return *this;
        }

    // Getters & Setters


    // Member Functions
typedef typename std::stack<T>::container_type::iterator it;

        it    begin()
        {
            return this->c.begin();
        }

        it    end()
        {
            return this->c.end();
        }

};

#endif