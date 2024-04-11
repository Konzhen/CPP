#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	try
	{
		ClapTrap *clap = new ClapTrap("Vincent");
		ScavTrap *scav = new ScavTrap("Ronan");
		FragTrap *frag = new FragTrap("Gigi");

		try 
		{
			clap->attack("Snake");
			clap->takeDamage(8);
			clap->beRepaired(2);
			scav->attack("Demon");
			clap->takeDamage(3);
			scav->takeDamage(1);
			scav->takeDamage(4);
			frag->takeDamage(81);
			frag->takeDamage(0);
			for (size_t i = 0; i < 5; i++)
			{
				frag->beRepaired(5);
			}
			for (size_t i = 0; i < 3; i++)
			{
				frag->attack("Fly");
				frag->attack("Orc");
			}
			scav->guardGate();
			frag->highFivesGuys();
			frag->takeDamage(500);
		}
		catch (ClapTrap *clap)
		{
			std::cout << "ClapTrap:" << clap->getName() << " suffered from its wounds." << std::endl;
		}
		frag->highFivesGuys();
		frag->takeDamage(81);
		delete (clap); 
		delete (scav);
		delete (frag);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Wrong damage as parameter" << std::endl;
	}
}