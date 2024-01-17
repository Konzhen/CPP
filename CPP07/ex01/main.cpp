#include "iter.hpp"

template <typename T>
void print(T &arg)
{
    std::cout << arg << std::endl;
}

int main()
{
    std::string lst[] = {"Voila", "un", "beau", "petit", "message."};
    size_t s = sizeof(lst) / sizeof(std::string);
    std::cout << "size:" << s << std::endl << std::endl;

    ::iter<std::string>(lst, s, &print);
    std::cout << std::endl << std::endl;

    int lst2[8] = {2, 4, 8, 16, 32, 64, 128, 256};
    s = sizeof(lst2) / sizeof(int);
    std::cout << "size:" << s << std::endl << std::endl;
    ::iter<int>(lst2, s, &print);
    std::cout << std::endl;
}