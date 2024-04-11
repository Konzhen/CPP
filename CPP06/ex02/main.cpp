#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    std::srand(std::time(0));
    Base    *p;

    int i = std::rand() % 3;
    switch (i)
    {
        case 0:
        {
            p = new A();
            return p;
        }
        case 1:
        {
            p = new B();
            return p;
        }
        case 2:
        {
            p = new C();
            return p;
        }
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    A   *a = dynamic_cast<A *>(p);
    B   *b = dynamic_cast<B *>(p);
    C   *c = dynamic_cast<C *>(p);
    
    if (a)
        std::cout << "Object type pointer: A" << std::endl;
    if (b)
        std::cout << "Object type pointer: B" << std::endl;
    if (c)
        std::cout << "Object type pointer: C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A   a = dynamic_cast<A &>(p);
        std::cout << "Object type reference: A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B   b = dynamic_cast<B &>(p);
        std::cout << "Object type reference: B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C   c = dynamic_cast<C &>(p);
        std::cout << "Object type reference: C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}

int main()
{
    {
        Base    *x = generate();
        Base    *y = generate();

        identify(x);
        std::cout << std::endl;
        identify(*y);
        delete x;
        delete y;
    }
}