#include <iostream>

template <typename T>
void    easyfind(T &lst, int &n)
{
    std::iterator it = std::find(lst.begin(), lst.end(), n);

    if (it != lst.end)
        std::cout << n << " finded at index : " <<  it.index << std::endl;
    else
        throw std::runtime_error;
}