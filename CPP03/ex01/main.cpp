#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	try
	{
		ClapTrap *clap = new ClapTrap("Vincent");
		ScavTrap *scav = new ScavTrap("Ronan");

		try 
		{
			clap->attack("Snake");
			clap->takeDamage(5);
			clap->beRepaired(2);
			scav->attack("Demon");
			clap->takeDamage(3);
			scav->takeDamage(1);
			scav->takeDamage(4);
			scav->takeDamage(500);
			scav->takeDamage(0);
			for (size_t i = 0; i < 18; i++)
			{
				scav->beRepaired(1);
			}
			for (size_t i = 0; i < 7; i++)
			{
				scav->attack("Parot");
			}
			scav->guardGate();
		}
		catch (ClapTrap *clap)
		{
			std::cout << "ClapTrap:" << clap->getName() << " suffered from its wounds." << std::endl;
		}
		clap->attack("Poulet");
		scav->guardGate();
		delete (clap); 
		delete (scav);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Wrong damage as parameter" << std::endl;
	}
}