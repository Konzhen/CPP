#include "iter.hpp"

template <typename T>
void print(T &str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string lst[5] = {"a", "b", "c", "d", "e"};

    iter<std::string>(lst, lst->length(), &print);
}