 #include "PmergeMe.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                            //
//--------------------------------------------------------------------------//



template<typename Container>
PmergeMe<Container>::PmergeMe() : data(), last(-1), time(0) 
{

}

template <typename Container>
PmergeMe<Container>::PmergeMe(char **input) : data()
{
    time = 0;
    last = -1;
    for(size_t i = 0; input[i]; i++)
    {
        if (!is_number(input[i]) || strtod(input[i], NULL) > INT_MAX)
            throw std::invalid_argument("Error ");
        data.push_back(ft_stoa(input[i]));
    }
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other)
{
    data = other.data;
}

template<typename Container>
PmergeMe<Container>::~PmergeMe()
{

}

//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        data = other.data;
        last = other.last;
        time = other.time;
    }
    return (*this);
}

//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//
template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> >()
{
    return ("vector");
}

template <>
std::string getContainerName<std::deque<int> >()
{
    return ("deque");
}

//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

template <typename Container>
void PmergeMe<Container>::sort()
{
    std::clock_t start = std::clock();
    pair_vector pairs = pairing(data);
    int_vector insertionIndexes = indexing(data.size());

    if (pairs.size() == 0)
    {
        data.push_back(last);
        time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return;
    }

    sort_pairs(pairs);
    data.clear();
    data.push_back(pairs[0].second);

    for (size_type i = 0; i < pairs.size(); i++)
        data.push_back(pairs[i].first);
    for (size_t i = 0; i < insertionIndexes.size(); i++)
    {
        if (size_t(insertionIndexes[i] - 1) >= pairs.size())
            continue;
        int index = binary_search(pairs[insertionIndexes[i] - 1].second);
        data.insert(data.begin() + index, pairs[insertionIndexes[i] - 1].second);
    }
    if (last != -1)
    {
        int index = binary_search(last);
        data.insert(data.begin() + index, last);
    }
    clock_t endTime = clock();
    time = static_cast<double>(endTime - start) * 1e6 / CLOCKS_PER_SEC;
}

template <typename Container>
typename PmergeMe<Container>::pair_vector PmergeMe<Container>::pairing(Container &data)
{
    pair_vector pairs;

    if (data.size() % 2 != 0)
    {
        last = data.back();
        data.pop_back();
    }
    for (size_type i = 0; i < data.size(); i += 2)
    {
        if (data[i] < data[i + 1])
            std::swap(data[i], data[i + 1]);
        pairs.push_back(std::make_pair(data[i], data[i + 1]));
    }
    return (pairs);
}

template <typename Container>
void PmergeMe<Container>::sort_pairs(pair_vector &pairs)
{
    if (pairs.size() <= 1)
        return;

    size_type middle = pairs.size() / 2;
    pair_vector leftHalf(pairs.begin(), pairs.begin() + middle);
    pair_vector rightHalf(pairs.begin() + middle, pairs.end());

    sort_pairs(leftHalf);
    sort_pairs(rightHalf);

    size_type leftIdx = 0;
    size_type rightIdx = 0;
    size_type idx = 0;

    while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size())
        pairs[idx++] = leftHalf[leftIdx].first < rightHalf[rightIdx].first ? leftHalf[leftIdx++] : rightHalf[rightIdx++];

    while (leftIdx < leftHalf.size())
        pairs[idx++] = leftHalf[leftIdx++];

    while (rightIdx < rightHalf.size())
        pairs[idx++] = rightHalf[rightIdx++];
}

template <typename Container>
int PmergeMe<Container>::binary_search(int target)
{
    int left = 0;
    int right = data.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (data[middle] == target)
            return middle;
        else if (data[middle] < target)
            left = middle+1;
        else
            right = middle-1;
    }
    return (left);
}

template <typename Container>
int_vector PmergeMe<Container>::indexing(size_t size)
{
    int_vector indexes;
    int jacobsthalSequence[size + 1];
    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;
    for (size_t i = 2; indexes.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        i != 2 ? indexes.push_back(jacobsthalSequence[i]) : (void)0;

        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            indexes.push_back(j);
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return (indexes);
}

template<typename Container>
void PmergeMe<Container>::print_data() const
{
    for (size_t i = 0; i < data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::print_time() const
{
    std::cout << "Sorting the suite using " << getContainerName< Container >() << " : " << time << " µs" << std::endl;
}

template<typename Container>
int PmergeMe<Container>::ft_stoa(const char *str)
{
    std::istringstream  ss(str);
    int                 number;
    ss >> number;
    return (number);
}

template<typename Container>
bool PmergeMe<Container>::is_number(const std::string& s)
{
    if (s.empty() || s[0] == '-')
        return (false);

    size_t i = 0;

    if (s[0] == '+' && s.length() == 1)
        return (false);
    else if (s[0] == '+')
        i++;

    for (; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return (false);

    return (true);
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;