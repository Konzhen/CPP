#include "Harl.hpp"

int	main()
{
	Harl	h;

	std::cout << "test: false" << std::endl;
	h.complain("test");
	std::cout << "debug:" << std::endl;
	h.complain("debug");
	std::cout << "info:" << std::endl;
	h.complain("info");
	std::cout << "warning:" << std::endl;
	h.complain("warning");
	std::cout << "debugg: false" << std::endl;
	h.complain("debugg");
	std::cout << "Error: false" << std::endl;
	h.complain("Error");
}