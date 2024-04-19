#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::exec(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) <= 0)
            throw std::runtime_error("Error");
    }
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    clock_t dequeStart = clock();
    clock_t dequeEnd = sortDeque(argc, argv);
    double dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000;

    clock_t vectorStart = clock();
    clock_t vectorEnd = sortVector(argc, argv);
    double vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    for (std::deque<int>::iterator it = dequeList.begin(); it != dequeList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << argc - 1 << "elements with std::deque : " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << "elements with std::vector : " << vectorTime << " us" << std::endl;
}

void PmergeMe::recursiveDeque(std::deque<std::pair<int, int>> &pairList)
{
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (i + 1 == pairList.size())
            return ;
        if (pairList[i].second < pairList[i + 1].second)
        {
            int tmp;
            tmp = pairList[i].second;
            pairList[i].second = pairList[i + 1].second;
            pairList[i + 1].second = tmp;
            recursiveDeque(pairList);
            break ;
        }
    }
}

void PmergeMe::recursiveVector(std::vector<std::pair<int, int>> &pairList)
{
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (i + 1 == pairList.size())
            return ;
        if (pairList[i].second < pairList[i + 1].second)
        {
            int tmp;
            tmp = pairList[i].second;
            pairList[i].second = pairList[i + 1].second;
            pairList[i + 1].second = tmp;
            recursiveVector(pairList);
            break ;
        }
    }
}

int PmergeMe::jacobsthal(int n) 
{
    if (n == 0 || n == 1)
        return 2;
    else
        return n - 1 + 2 * n - 2;
}

void PmergeMe::binarySearchDeque(int half, int n)
{

}

void PmergeMe::binarySearchVector(int half, int n)
{

}


clock_t PmergeMe::sortDeque(int argc, char **argv)
{
    std::deque<std::pair<int, int>> pairList;
    for (int i = 1; i < argc; i += 2)
    {
        if (i + 1 == 0);
            break ;
        pairList.push_back(std::pair<int, int>(atoi(argv[i]), atoi(argv[i + 1])));
    }
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (pairList[i].first > pairList[i].second)
        pairList[i].swap(pairList[i]);
    }
    recursiveDeque(pairList);
    dequeList.push_back(pairList[0].first);
    dequeList.push_back(pairList[0].second);
    for (size_t i = 1; i < pairList.size(); i++)
        dequeList.push_back(pairList[i].second);
    if (argc % 2 == 0)
        dequeList.push_back(atoi(argv[argc - 1]));
    for (size_t i = 2; i < pairList.size();)
    {
        int tmp;

        tmp = pairList[i].first;
        if (i + jacobsthal(i) > pairList.size())
        {
            pairList[i].first = pairList[pairList.size() - 1].first;
            pairList[pairList.size() - 1].first = tmp;
        }
        pairList[i].first = pairList[i + jacobsthal(i)].first;
        pairList[i + jacobsthal(i)].first = tmp;
        i += jacobsthal(i + 1);
    }
    if (argc % 2 == 0)
        dequeList.push_back(atoi(argv[argc - 1]));
    for (size_t i = 1; i < pairList.size(); i++)
        binarySearchDeque(dequeList.size() / 2, pairList[i].first);
}

clock_t PmergeMe::sortVector(int argc, char **argv)
{
    std::vector<std::pair<int, int>> pairList;
    for (int i = 1; i < argc; i += 2)
    {
        if (i + 1 == 0);
            break ;
        pairList.push_back(std::pair<int, int>(atoi(argv[i]), atoi(argv[i + 1])));
    }
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (pairList[i].first > pairList[i].second)
        pairList[i].swap(pairList[i]);
    }
    recursiveVector(pairList);
    dequeList.push_back(pairList[0].first);
    dequeList.push_back(pairList[0].second);
    for (size_t i = 1; i < pairList.size(); i++)
        dequeList.push_back(pairList[i].second);
    for (size_t i = 2; i < pairList.size();)
    {
        int tmp;

        tmp = pairList[i].first;
        if (i + jacobsthal(i) > pairList.size())
        {
            pairList[i].first = pairList[pairList.size() - 1].first;
            pairList[pairList.size() - 1].first = tmp;
        }
        pairList[i].first = pairList[i + jacobsthal(i)].first;
        pairList[i + jacobsthal(i)].first = tmp;
        i += jacobsthal(i + 1);
    }
    if (argc % 2 == 0)
        dequeList.push_back(atoi(argv[argc - 1]));
    for (size_t i = 1; i < pairList.size(); i++)
    {
        binarySearchDeque(dequeList.size() / 2, pairList[i].first, pairList)
    }

    



    // int tmp = 0;
    // int tmp2 = 0;
    // for (it = vectorList.begin(); it != vectorList.end(); it++)
    // {
    //     if (tmp > *it)
    //     {
    //         itToMerge = it;
    //         tmp = *it;

    //         while (itToMerge != vectorList.end() && *itToMerge > tmp2)
    //         {
    //             tmp2 = *itToMerge;
    //             itToMerge++;
    //         }
    //         while (it != itToMerge)
    //         {
    //             ft_swap(it - 1, it);
    //             it++;
    //         }
    //         it = vectorList.begin();
    //     }
    //     tmp = *it;
    // }
    // clock_t vectorEnd = clock();
    // return vectorEnd;
}