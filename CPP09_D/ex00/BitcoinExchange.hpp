#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

//--------------------------------------------------------------------------//
//    -                           - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <map>

//--------------------------------------------------------------------------//
//                                 - BITCOINS -                             //
//--------------------------------------------------------------------------//

//--PUBLIC------------------------------------------------------------------//
                           // - FUNCTIONS - //
std::map<std::string, float>    getData(void);
void    			            PrintMap(std::map<std::string, float> mymap);
void    			            ReadInput(std::string file, std::map<std::string, float> database);
int     			            Parsing(int year, int month, int day, std::string strrate, float nbrate, std::string line);
void    			            PrintOuput(std::string inputdate, float bitcoins, std::map<std::string, float> database);

#endif