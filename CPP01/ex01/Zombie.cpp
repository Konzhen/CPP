#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout <<_name << ": SsbuuuuuaaaaarrrkkkzzZ..." <<std::endl;
}

void	Zombie::init(std::string name)
{
	_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}