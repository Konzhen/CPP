#include "whatever.hpp"

int main()
{

    {
        int a = 2;
        int b = 3;
        ::swap(a, b);
        std::cout << "a = " << a << " b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";
        
        ::swap(c, d);
        std::cout << "c = " << c << " d = " << d << std::endl;
        std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
        std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    }

    {
    int a = 24;
    int b = 42;

    std::cout << "a:" << a << " b:" << b << std::endl;
    std::cout << "max:" << ::max(a, b) << std::endl;
    std::cout << "min:" << ::min(a, b) << std::endl;
    ::swap(a, b);
    std::cout << "a:" << a << " b:" << b << std::endl;
    std::cout << std::endl;

    std::string s = "aaa";
    std::string t = "zzz";

    std::cout << "s:" << s << " t:" << t << std::endl;
    std::cout << "max:" << ::max(s, t) << std::endl;
    std::cout << "min:" << ::min(s, t) << std::endl;
    ::swap(s, t);
    std::cout << "s:" << s << " t:" << t << std::endl;
    std::cout << std::endl;
    }

}