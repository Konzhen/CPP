#include <iostream>

template <typename T>
void    swap(T &a, T &b)
{
    T   cpy = a;
    a = b;
    b = cpy;
}

template <typename T>
const   T &max(const T &a, const T &b)
{
    if (a > b)
        return (a);
    return b;
}

template <typename T>
const   T &min(const T &a, const T &b)
{
    if (a < b)
        return (a);
    return b;
}