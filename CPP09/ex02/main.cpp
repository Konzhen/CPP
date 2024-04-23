#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 3)
			throw std::runtime_error("Error");
		PmergeMe p;
		p.exec(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}