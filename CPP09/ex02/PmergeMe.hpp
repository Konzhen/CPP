#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iterator>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

    template <typename T>
        void ft_swap(iterator a, T *b);
        void exec(int argc, char **argv);
        clock_t sortDeque();
        clock_t sortVector();

        std::deque<int> dequeList;
        std::vector<int> vectorList;
};

#endif