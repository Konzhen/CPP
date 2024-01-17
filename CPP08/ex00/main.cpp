#include "easyfind.hpp"
#include <vector>

int main()
{
    try
    {
        int lst = {1, 2, 4, 8, 16, 32, 64, 128, 256};
        ::easyfind(lst, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}