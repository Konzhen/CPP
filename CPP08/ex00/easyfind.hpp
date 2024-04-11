#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class ArgumentNotFound : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return (" is not in the list, sadly...");
        }
};

template <typename T>
int easyfind(T &lst, int n)
{
    typename T::iterator iter = std::find(lst.begin(), lst.end(), n);

    if (iter == lst.end())
        throw ArgumentNotFound();
    else
        std::cout << n << " is in the list!" << std::endl;
    return (*iter);
}