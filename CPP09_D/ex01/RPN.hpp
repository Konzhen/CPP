#ifndef RPN_HPP
# define RPN_HPP

//--------------------------------------------------------------------------//
//    -                           - INCLUDES -                                -    //
//--------------------------------------------------------------------------//

# include <stack>
# include <string>
# include <exception>
# include <iostream>
//--------------------------------------------------------------------------//
//                                 - CLASS -                                    //
//--------------------------------------------------------------------------//

class RPN
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
    std::string         input;
    std::stack<float>   stack;
    bool                isValidChar(char c) const;
    float               operation(float first, float second, char token) const;

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
    float calculate();


                           // - FUNCTIONS - //

    // Constructor & Destructors
    RPN();
    RPN(std::string str);
    RPN(const RPN& r);
    ~RPN();


    // Operators
    RPN& operator=(const RPN& rpn);

    // Getters & Setters


    // Member Functions
};

#endif