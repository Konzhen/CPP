#ifndef HUMANB_HPP
#define HUMANB_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

#include <iostream>
#include "Weapon.hpp"

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class HumanB
{
//  PRIVATE
    private:
        Weapon      *_weapon;
        std::string _name;      

//  PUBLIC
    public:
    //  Constructor & Destructor
        HumanB(std::string name);
        ~HumanB();

        //  Getters & Setters
 
        //  Members functions
        void    setWeapon(Weapon &weapon);
        void    attack();
};

#endif