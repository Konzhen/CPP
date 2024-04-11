#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        void swap(int a, int b);
        void exec(int argc, char **argv);
        clock_t sortDeque();
        clock_t sortVector();

        std::deque<int> dequeList;
        std::vector<int> vectorList;
};

#endif