#ifndef WEAPON_HPP
#define WEAPON_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

#include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Weapon
{
//  PRIVATE
    private:
        std::string _type;

//  PUBLIC
    public:
    //  Constructor & Destructor
        Weapon(std::string type);
        ~Weapon();

        //  Getters & Setters
        std::string getType(void) const;
        void        setType(std::string type);

        //  Members functions
};

#endif