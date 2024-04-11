#ifndef HUMANA_HPP
#define HUMANA_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

#include <iostream>
#include "Weapon.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class HumanA
{
//  PRIVATE
    private:
        Weapon      _weapon;
        std::string _name;

//  PUBLIC
    public:
    //  Constructor & Destructor
        HumanA(std::string name, Weapon weapon);
        ~HumanA();

        //  Getters & Setters
 
        //  Members functions
        void    attack();
};

#endif