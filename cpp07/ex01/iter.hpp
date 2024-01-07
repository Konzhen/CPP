#include <iostream>

template <typename T>
void    iter(T *a, size_t b, void (*f)(T &p))
{
    for (size_t i = 0; i < b; i++)
    {
        f(a[i]);
    }
}
