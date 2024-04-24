#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <utility>
#include <string>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        void exec(int argc, char **argv);

        void recursiveDeque(std::deque<std::pair<int, int> > &pairList);
        void recursiveVector(std::vector<std::pair<int, int> > &pairList);
        void binarySearchDeque(size_t half, int n);
        void binarySearchVector(size_t half, int n);
        clock_t sortDeque(int argc, char **argv);
        clock_t sortVector(int argc, char **argv);
        std::deque<int> dequeList;
        std::vector<int> vectorList;
        int quarter;
};

#endif