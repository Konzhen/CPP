#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie *newZombie(std::string name);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "You have to select at least one target to receive the virus-T... Brrrr...";		
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		Zombie	*zombie = newZombie(argv[i]);

		std::cout << "- Stack - " << std::endl;
		randomChump(argv[i]);
		std::cout << "- Heap -" << std::endl;
		zombie->announce();
		delete(zombie);
		std::cout << std::endl;
	}
}