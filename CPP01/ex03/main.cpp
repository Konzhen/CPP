#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(int argc, char **argv)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;
	}
	if (argc > 1)
	{
		for (int i = 0; i < argc - 1; i++)
		{
			Weapon weaponA = Weapon(argv[i + 1]);
			HumanA A("A", weaponA);
			A.attack();
			Weapon weaponB = Weapon("great spear");
			HumanB B("B");
			B.attack();
			B.setWeapon(weaponB);
			B.attack();
			std::cout << std::endl;
		}
		
	}
return 0;
}