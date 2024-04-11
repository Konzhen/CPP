#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include <string.h>
# include <regex.h>
# include <sstream>

enum Type
{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    NONDISPLAYABLE
};

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class ScalarConverter
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors
        ScalarConverter();
        ScalarConverter(ScalarConverter const &scalarconverter);
        ~ScalarConverter();

    // Operators
        ScalarConverter &operator=(ScalarConverter const &scalarconverter);

    // Getters & Setters


    // Member Functions
        static bool                 isInt(const char *p);
        static bool                 isFloat(const char *p);
        static bool                 isChar(const char *p);
        static bool                 isDouble(const char *p);
        static int                  findType(const char *p);
        static std::string          convertToInt(std::string p, int src);
        static std::string          convertToFloat(std::string p, int src);
        static std::string          convertToChar(std::string p, int src);
        static std::string          convertToDouble(std::string p, int src);

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


    // Operators
        

    // Getters & Setters


    // Member Functions  

    static void    convert(std::string const &p);

};

#endif