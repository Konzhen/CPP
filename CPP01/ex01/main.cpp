#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "You have to select at least one target to receive the virus-T... Brrrr...";		
		return (1);
	}
	if (!atoi(argv[1]))
	{
		std::cout << "Firstly, you have to print how many members each of your hordes are composed of, then name each one of them... Brrrr...";		
		return (1);		
	}
	for (int i = 2; i < argc; i++)
	{
		Zombie	*horde = zombieHorde(atoi(argv[1]), argv[i]);
		for (int i = 0; i < atoi(argv[1]); i++)
			horde[i].announce();
		delete []horde;
		std::cout << std::endl;
	}
}