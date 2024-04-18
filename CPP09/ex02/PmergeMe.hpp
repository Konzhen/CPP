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

        void exec(int argc, char **argv);

        void recursiveDeque(std::deque<std::pair<int, int>> &pairList);
        void recursiveVector(std::vector<std::pair<int, int>> &pairList);
        clock_t sortDeque();
        clock_t sortVector();

        std::deque<int> dequeList;
        std::vector<int> vectorList;
};

#endif