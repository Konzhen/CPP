#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	_name = name;
}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with his bare hands, well... that' s ineffective... you peasant..." << std::endl;	
}