#include "Base.hpp"

Base *generate(void)
{
    std::srand(std::time(0));

    int i = std::rand() % 3;
    switch (i)
    {
        case 1:
            return new A;
        case 2:
            return new B;
        case 3:
            return new C;
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
    A   &a = dynamic_cast<A &>(p);
    B   &b = dynamic_cast<B &>(p);
    C   &c = dynamic_cast<C &>(p);

    if (a)
        std::cout << "Object type reference: A" << std::endl;
    if (b)
        std::cout << "Object type reference: B" << std::endl;
    if (c)
        std::cout << "Object type reference: C" << std::endl;
}

int main()
{
	Base	*base;

	base =  base->generate();
}