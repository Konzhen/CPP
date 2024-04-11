#ifndef BRAIN_HPP
#define BRAIN_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include <ctime>
# include <cstdlib>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Brain
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
                           
        std::string _ideas[100];

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
        Brain();
        Brain(Brain const &brain);
        ~Brain();


    // Operators
        Brain &operator=(Brain const &brain);

    // Getters & Setters


    // Member Functions
        void    getIdeas() const;
        void    getRandomIdea() const;

};

#endif