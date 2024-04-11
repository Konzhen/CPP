#include "ScavTrap.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap:" << getName() << " Oh yeah, i'm a ScaaavTrap now!" << std::endl;
	setHp(100);
	setEp(50);
	setDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap) : ClapTrap(scavtrap)
{
	setName(scavtrap.getName());
	setHp(scavtrap.getHp());
	setEp(scavtrap.getEp());
	setDamage(scavtrap.getDamage());	
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap:" << getName() << " Oh no, i'm not ScaaavTrap anymore..." << std::endl;	
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

ScavTrap    &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	setName(scavtrap.getName());
	setHp(scavtrap.getHp());
	setEp(scavtrap.getEp());
	setDamage(scavtrap.getDamage());

	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void ScavTrap::attack(const std::string& target)
{
	if (_hp == 0)
		return ;
	try
	{
		if (_ep == 0)
			throw _ep;
		_ep--;
		std::cout << "ScavTrap:" << getName() << " attacks " << target
			<< ", causing " << getDamage() << " points of damage! "
			<< getEp() << " Ep remaining." << std::endl;
	}
	catch (unsigned int ep)
	{
		std::cout << "Not enough energy points." << std::endl;
	}
}

void		ScavTrap::guardGate()
{
	if (_hp == 0)
		return ;
	std::cout << "ScavTrap:" << getName() << " Entered Gate Keeper mode" << std::endl;
}