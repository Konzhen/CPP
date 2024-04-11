 #include "span.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                      //
//--------------------------------------------------------------------------//

Span::Span(unsigned int n): _maxN(n)
{
    _v.reserve(_maxN);
}

Span::Span(unsigned int n, int max): _maxN(n)
{
    _v.reserve(_maxN);
    srand(time(0));
    for (size_t i = 0; i < _maxN; i++)
    {
        _v.push_back(rand() % max);
    }
    
}

Span::Span(Span const &span)
{
    *this = span;
    _v.reserve(span._maxN);
}

Span::~Span()
{

}


//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//

Span    &Span::operator=(const Span &span)
{
    _maxN = span._maxN;
    _v.reserve(span._maxN);
    return (*this);
}


//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//

std::vector<int> Span::getVector() const
{
    return (_v);
}

unsigned int     Span::getMaxN() const
{
    return (_maxN);
}


//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

void    Span::printAll()
{
    for (size_t i = 0; i < _v.size(); i++)
    {
        std::cout << "at index " << i << " correspondind value is: "<< _v[i] << std::endl;
    }
    
}

void    Span::addNumber(int n)
{
    if (_v.size() >= _maxN)
        throw std::out_of_range("Max size reached");
    _v.push_back(n);
}

int     Span::longestSpan()
{
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements");
    _min = std::min_element(_v.begin(), _v.end());
    _max = std::max_element(_v.begin(), _v.end());

    return (*_max - *_min);
}

int     Span::shortestSpan()
{
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements");
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    int value = tmp[1] - tmp[0];
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < value)
            value = tmp[i + 1] - tmp[i];
    }
    return (value);
}