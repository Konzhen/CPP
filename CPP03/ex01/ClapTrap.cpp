#include "ClapTrap.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

ClapTrap::ClapTrap(std::string name): _hp(10), _ep(10), _damage(0)
{
	setName(name);
	std::cout << "Allow me to introduce myself : I am a CL4P-TP steward bot, but my friends call me "
		<< getName() << "! Or they would if any of them were still alive." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
	setName(claptrap.getName());
	setHp(claptrap.getHp());
	setEp(claptrap.getEp());
	setDamage(claptrap.getDamage());
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap:" << getName() << " is dead..." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

ClapTrap	&ClapTrap::operator=(const ClapTrap &claptrap)
{
	setName(claptrap.getName());
	setHp(claptrap.getHp());
	setEp(claptrap.getEp());
	setDamage(claptrap.getDamage());

	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}
        
int 	ClapTrap::getHp(void) const
{
	return (_hp);
}
        
void	ClapTrap::setHp(int hp)
{
	_hp = hp;
}
        
int 	ClapTrap::getEp(void) const
{
	return (_ep);
}
        
void	ClapTrap::setEp(int ep)
{
	_ep = ep;
}
        
int 	ClapTrap::getDamage(void) const
{
	return (_damage);
}
        
void	ClapTrap::setDamage(int damage)
{
	if (damage == 0)
		throw std::invalid_argument("Wrong Damage value.");
	_damage = damage;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
		return ;
	try
	{
		if (_ep == 0)
			throw _ep;
		_ep--;
		std::cout << "Claptrap:" << getName() << " attacks " << target
			<< ", causing " << getDamage() << " points of damage! "
			<< getEp() << " Ep remaining." << std::endl;
	}
	catch (unsigned int ep)
	{
		std::cout << "Not enough energy points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
		return ;
	if (amount == 0)
	{
		std::cout << "Claptrap:" << getName() << " Laughs and exclaims \"It didn' t even tickle me, pff, you peasant!\" "
			<< getHp() << " Hp remaining." << std::endl;
		return ;
	}
	else if (amount >= _hp)
	{
		setHp(0);
		std::cout << "Claptrap:" << getName() << " takes " << amount
			<< " of damages! " << getHp() << " Hp remaining." << std::endl;
		throw (this);
		return ;
	}
	_hp -= amount;
	std::cout << "Claptrap:" << getName() << " takes " << amount
		<< " of damages! " << getHp() << " Hp remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
		return ;
	try
	{
		if (_ep == 0)
			throw _ep;
		_ep--;
		_hp += amount;
		std::cout << "Claptrap:" << getName() << " is healing for " << amount
			<< " health points " << getHp() << " Hp remaining, "
			<< getEp() << " Ep remaining." << std::endl;
	}
	catch (unsigned int ep)
	{
		std::cout << "Not enough energy points" << std::endl;
	}
}
