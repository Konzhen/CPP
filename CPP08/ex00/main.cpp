#include "easyfind.hpp"
#include <vector>
#include <set>


int main()
{
    std::vector<int> v;
    int n = 4;
    try
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(4);
        v.push_back(8);
        v.push_back(16);
        easyfind(v, n);
    }
    catch(const std::exception& e)
    {
        std::cerr << n << e.what() << '\n';
    }
    
    n = 5;
    try
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(4);
        v.push_back(8);
        v.push_back(16);
        easyfind(v, n);
    }
    catch(const std::exception& e)
    {
        std::cerr << n << e.what() << '\n';
    }


    std::set<int> s;
    n = 16;
    try
    {
        s.insert(1);
        s.insert(2);
        s.insert(4);
        s.insert(8);
        s.insert(16);
        easyfind(s, n);
    }
    catch(const std::exception& e)
    {
        std::cerr << n << e.what() << '\n';
    }
    
    n = 42;
    try
    {
        s.insert(1);
        s.insert(2);
        s.insert(4);
        s.insert(8);
        s.insert(16);
        easyfind(v, n);
    }
    catch(const std::exception& e)
    {
        std::cerr << n << e.what() << '\n';
    }
}