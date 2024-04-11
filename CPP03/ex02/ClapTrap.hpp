#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class ClapTrap
{
//--PRIVATE-----------------------------------------------------------------//
    protected:
                           // - VARIABLES - //
        
        std::string _name;
        unsigned int _hp;
        unsigned int _ep;
        unsigned int _damage;

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
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &claptrap);
        ~ClapTrap();

    // Operators
        ClapTrap &operator=(const ClapTrap &claptrap);

    // Getters & Setters
        std::string getName(void) const;
        void        setName(std::string name);
        int         getHp(void) const;
        void        setHp(int hp);
        int         getEp(void) const;
        void        setEp(int ep);
        int         getDamage(void) const;
        void        setDamage(int damage);

    // Member Functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};

#endif