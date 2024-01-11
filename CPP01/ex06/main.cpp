#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of parameters." << std::endl;
		return (1);
	}
	Harl	h;

	h.complain(argv[1]);
}