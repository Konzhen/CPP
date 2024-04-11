#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap:" << getName() << " Aaaaaaah, i became a devil FragTraaaap!" << std::endl;
	setHp(100);
	setEp(100);
	setDamage(30);
}

FragTrap::FragTrap(FragTrap const &fragtrap) : ClapTrap (fragtrap)
{
	setName(fragtrap.getName());
	setHp(fragtrap.getHp());
	setEp(fragtrap.getEp());
	setDamage(fragtrap.getDamage());
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap:" << getName() << " Finally, i'm free..." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

FragTrap    &FragTrap::operator=(const FragTrap &fragtrap)
{
	setName(fragtrap.getName());
	setHp(fragtrap.getHp());
	setEp(fragtrap.getEp());
	setDamage(fragtrap.getDamage());

	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	FragTrap::highFivesGuys()
{
	if (_hp == 0)
		return ;
	std::cout << "FragTrap:" << getName() << " Please, come on, High Five with me boy !" << std::endl;
}
