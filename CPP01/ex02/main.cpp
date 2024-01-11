#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << &string << " - " << stringPTR << " - " << &stringREF << std::endl;
	std::cout << string << " - " << *stringPTR << " - " << stringREF << std::endl;
}