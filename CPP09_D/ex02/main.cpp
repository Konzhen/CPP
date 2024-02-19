#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "Wrong input.\nRun the program this way -> ./PmergMe <numbers list>" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe<std::vector<int> > vec(argv + 1);

        std::cout << "Before:\t";
        vec.print_data();
        vec.sort();
        PmergeMe<std::deque<int> > dqueue(argv + 1);
        dqueue.sort();
        std::cout << "After:\t";
        dqueue.print_data();
        vec.print_time();
        dqueue.print_time();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}