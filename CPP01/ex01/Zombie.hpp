#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include <stdlib.h>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Zombie
{

    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();
        void    init(std::string name);
        void    announce( void );
        Zombie	*zombieHorde(int N, std::string name);
};

#endif