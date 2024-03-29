#include "BitcoinExchange.hpp"

int main(int argc, char ** argv)
{
    try
    {
        if (argc != 2)
            throw std::runtime_error("Error: Exactly one argument is needed.");
        BitcoinExchange::exec(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}