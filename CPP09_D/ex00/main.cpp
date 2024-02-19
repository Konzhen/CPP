#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<std::string, float>	database;

    if (argc != 2)
    {
	std::cerr << "Wrong input.\nRun the program this way -> ./btc <path to input.txt>" << std::endl;
	return (1);
    }
    try
    {
        std::string   line;
        std::ifstream file(argv[1]);
	    file.open(argv[1], std::ifstream::in);
	    if (!file.is_open())
	    	throw std::runtime_error("Error: Could not open input file");
        database = getData();
        ReadInput(argv[1], database);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
	    return (1);
    }
    return (0);
}