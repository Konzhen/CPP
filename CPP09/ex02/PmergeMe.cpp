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
        std::string s = argv[i];
        if (atoi(argv[i]) <= 0 || s.find(".") != std::string::npos)
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
    // std::cout << std::endl;
    // for (std::vector<int>::iterator it2 = vectorList.begin(); it2 != vectorList.end(); it2++)
    //     std::cout << *it2 << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vectorTime << " us" << std::endl;
}

void PmergeMe::recursiveDeque(std::deque<std::pair<int, int> > &pairList)
{
    for (size_t i = 0; i < pairList.size() - 1; i++)
    {
        if (pairList[i].second > pairList[i + 1].second)
        {
            std::pair<int, int> tmp;

            tmp = pairList[i];
            pairList[i] = pairList[i + 1];
            pairList[i + 1] = tmp;
            i = -1;
        }
    }
}

void PmergeMe::recursiveVector(std::vector<std::pair<int, int> > &pairList)
{
    for (size_t i = 0; i < pairList.size() - 1; i++)
    {
        if (pairList[i].second > pairList[i + 1].second)
        {
            std::pair<int, int> tmp;

            tmp = pairList[i];
            pairList[i] = pairList[i + 1];
            pairList[i + 1] = tmp;
            i = -1;
        }
    }
}

void PmergeMe::binarySearchDeque(size_t half, int n)
{
    if (dequeList[half] > n)
    {
        half /= 2;
        if (dequeList[half] > n)
           half /= 2;
        else if (dequeList[half] < n)
           half += quarter / 2;
    } 
    else if (dequeList[half] < n)
    {
        half += quarter;
        if (dequeList[half] < n)
           half += quarter / 2;
        else if (dequeList[half] < n)
           half -= quarter / 2;
    }
    while (true)
    {
        if (half == 0 && dequeList[half] > n)
        {
            std::deque<int>::iterator it = dequeList.begin();
            it += half;
            dequeList.insert(it, n);
            return ;            
        }   
        else if (dequeList[half - 1] <= n && dequeList[half] >= n)
        {
            std::deque<int>::iterator it = dequeList.begin();
            it += half;
            dequeList.insert(it, n);
            return ;
        }
        else if (half == dequeList.size() - 1)
        {
            std::deque<int>::iterator it = dequeList.begin();
            it += half + 1;
            dequeList.insert(it, n);
            return ;            
        }
        else if (dequeList[half] > n)
            half--;
        else if (dequeList[half] < n)
            half++;
    }
}   

void PmergeMe::binarySearchVector(size_t half, int n)
{
    if (vectorList[half] > n)
    {
        half = half / 2;
        if (vectorList[half] > n)
           half = half / 2;
        else if (vectorList[half] < n)
           half += quarter / 2;
    } 
    else if (vectorList[half] < n)
    {
        half += quarter;
        if (vectorList[half] < n)
           half += quarter / 2;
        else if (vectorList[half] < n)
           half -= quarter / 2;
    }
    while (true)
    {
        if (half == 0)
        {
            std::vector<int>::iterator it = vectorList.begin();
            it += half;
            vectorList.insert(it, n);
            return ;            
        }
        else if ((vectorList[half - 1] <= n && vectorList[half] >= n) || half == vectorList.size() - 1)
        {
            std::vector<int>::iterator it = vectorList.begin();
            it += half;
            vectorList.insert(it, n);
            return ;
        }
        else if (half == vectorList.size() - 1)
        {
            std::vector<int>::iterator it = vectorList.begin();
            it += half + 1;
            vectorList.insert(it, n);
            return ;            
        }
        else if (vectorList[half] > n)
            half--;
        else if (vectorList[half] < n)
            half++;
    }
}


clock_t PmergeMe::sortDeque(int argc, char **argv)
{
    std::deque<std::pair<int, int> > pairList;
    for (int i = 1; i < argc; i += 2)
    {
        if (argv[i + 1] == NULL)
            break ;
        pairList.push_back(std::pair<int, int>(atoi(argv[i]), atoi(argv[i + 1])));
    }
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (pairList[i].first > pairList[i].second)
        {
            int tmp = pairList[i].first;
            pairList[i].first = pairList[i].second;
            pairList[i].second = tmp;
        }
    }
    recursiveDeque(pairList); 
    dequeList.push_back(pairList[0].first);
    dequeList.push_back(pairList[0].second);
    for (std::deque<int>::iterator it = dequeList.begin(); it != dequeList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    for (size_t i = 1; i < pairList.size(); i++)
        dequeList.push_back(pairList[i].second);
    quarter = dequeList.size() / 4;
    for (std::deque<int>::iterator it = dequeList.begin(); it != dequeList.end(); it++)
        std::cout << *it << " ";
    for (size_t i = 1; i < pairList.size(); i++)
        binarySearchDeque(dequeList.size() / 2, pairList[i].first);
    if (argc % 2 == 0)
        binarySearchDeque(dequeList.size() / 2, atoi(argv[argc - 1]));
    return (clock());
}



clock_t PmergeMe::sortVector(int argc, char **argv)
{
    std::vector<std::pair<int, int> > pairList;
    for (int i = 1; i < argc; i += 2)
    {
        if (argv[i + 1] == NULL)
            break ;
        pairList.push_back(std::pair<int, int>(atoi(argv[i]), atoi(argv[i + 1])));
    }
    for (size_t i = 0; i < pairList.size(); i++)
    {
        if (pairList[i].first > pairList[i].second)
        {
            int tmp = pairList[i].first;
            pairList[i].first = pairList[i].second;
            pairList[i].second = tmp;
        }
    }
    recursiveVector(pairList);
    vectorList.push_back(pairList[0].first);
    vectorList.push_back(pairList[0].second);
    for (size_t i = 1; i < pairList.size(); i++)
        vectorList.push_back(pairList[i].second);
    quarter = vectorList.size() / 4;
    for (size_t i = 1; i < pairList.size(); i++)
        binarySearchVector(vectorList.size() / 2, pairList[i].first);
    if (argc % 2 == 0)
        binarySearchVector(vectorList.size() / 2, atoi(argv[argc - 1]));
    return (clock());
}