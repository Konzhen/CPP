#include "ClapTrap.hpp"

int	main()
{
	try
	{
		ClapTrap *clap1 = new ClapTrap("Paul");
		ClapTrap *clap2 = new ClapTrap("Gaspard");
		ClapTrap *clap3 = new ClapTrap("Charles");

		clap1->setDamage(3);
		clap2->setDamage(8);
		clap3->setDamage(1);
		try 
		{
			clap1->attack("Snake");
			clap1->takeDamage(8);
			clap1->beRepaired(2);
			clap2->attack("Demon");
			clap1->takeDamage(3);
			clap2->takeDamage(1);
			clap2->attack("Slime");
			clap2->attack("Slime");
			clap2->attack("Slime");
			clap2->takeDamage(4);
			for (size_t i = 0; i < 12; i++)
			{
				clap2->beRepaired(1);
			}
			clap3->attack("Minotaur");
			clap3->beRepaired(150);
			clap3->takeDamage(0);
			clap3->takeDamage(75);
			clap1->attack("Void");
		}
		catch (ClapTrap *clap)
		{
			std::cout << "ClapTrap:" << clap->getName() << " suffered from its wounds." << std::endl;
		}
		clap1->attack("Bag1");
		clap2->attack("Bag2");
		clap3->attack("Bag3");
		delete (clap1); 
		delete (clap2);
		delete (clap3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Wrong damage as parameter" << std::endl;
	}
}