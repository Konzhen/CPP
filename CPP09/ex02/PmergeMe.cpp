#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

template <typename T>
void PmergeMe::ft_swap(T *a, T *b)
{
    int   tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void PmergeMe::exec(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) < 0)
            throw std::runtime_error("Error");
        dequeList.push_back(atoi(argv[i]));
        vectorList.push_back(atoi(argv[i]));
    }
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    clock_t dequeStart = clock();
    clock_t dequeEnd = sortDeque();
    double dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000;

    clock_t vectorStart = clock();
    clock_t vectorEnd = sortVector();
    double vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    for (std::deque<int>::iterator it = dequeList.begin(); it != dequeList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << argc - 1 << "elements with std::deque : " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << "elements with std::vector : " << vectorTime << " us" << std::endl;
}

clock_t PmergeMe::sortDeque()
{
    std::deque<int>::iterator it;
    std::deque<int>::iterator itToMerge;

    int tmp = 0;
    int tmp2 = 0;
    for (it = dequeList.begin(); it != dequeList.end(); it++)
    {
        if (tmp > *it)
        {
            itToMerge = it;
            tmp = *it;

            while (itToMerge != dequeList.end() && *itToMerge > tmp2)
            {
                tmp2 = *itToMerge;
                itToMerge++;
            }
            while (it != itToMerge)
            {
                ft_swap(it - 1, it);
                it++;
            }
            it = dequeList.begin();
        }
        tmp = *it;
    }
    clock_t dequeEnd = clock();
    return dequeEnd;
}

clock_t PmergeMe::sortVector()
{
    std::vector<int>::iterator it;
    std::vector<int>::iterator itToMerge;

    int tmp = 0;
    int tmp2 = 0;
    for (it = vectorList.begin(); it != vectorList.end(); it++)
    {
        if (tmp > *it)
        {
            itToMerge = it;
            tmp = *it;

            while (itToMerge != vectorList.end() && *itToMerge > tmp2)
            {
                tmp2 = *itToMerge;
                itToMerge++;
            }
            while (it != itToMerge)
            {
                ft_swap(it - 1, it);
                it++;
            }
            it = vectorList.begin();
        }
        tmp = *it;
    }
    clock_t vectorEnd = clock();
    return vectorEnd;
}