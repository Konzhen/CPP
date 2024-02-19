 #ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>
# include <map>
# include <fstream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <regex>
# include <ctime>
# include <limits.h>
# include <iomanip>

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class BitcoinExchange
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
        static std::map<std::string, long double> createBtcMap();
        static void evaluateInputWithBtc(std::string input, std::map<std::string, long double> &btc);

//--PUBLIC------------------------------------------------------------------//
    public:
                           // - VARIABLES - //


                           // - FUNCTIONS - //

    // Constructor & Destructors
        BitcoinExchange();
        ~BitcoinExchange();

    // Operators


    // Getters & Setters


    // Member Functions
        static void exec(std::string input);

};

#endif