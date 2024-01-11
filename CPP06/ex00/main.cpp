#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("No argument as input.");
		else if (argc > 2)
			throw std::invalid_argument("Too many arguments as input.");
		

		std::string	p(argv[1]);

		ScalarConverter::convert(p);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
		return (1);
	}
	return (0);
}