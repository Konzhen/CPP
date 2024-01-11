#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Zombie
{

    private:
        std::string _name;

    public:
        Zombie(std::string _name);
        ~Zombie();

        void    announce( void );
        Zombie *newZombie(std::string name);
};

#endif