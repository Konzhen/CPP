#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cout << "Need an input in one string" << std::endl;
        return (1);
    }
    std::string str(argv[1]);
    RPN rpn(str);
    try 
    {
        std::cout << rpn.calculate() << std::endl;
        return (0);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}