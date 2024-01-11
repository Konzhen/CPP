#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie;
	
	zombie = new (std::nothrow) Zombie(name);
	if (!zombie)
		return NULL;
	return (zombie);
}