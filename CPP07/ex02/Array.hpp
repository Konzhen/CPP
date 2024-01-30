#include <iostream>

template <typename T>
class Array
{
    public:

    class TooHighIndex : public std::exception
    {
        public :
        virtual const char* what() const throw()
        {
            return ("Too high index");
        }
    };
    
        Array() : _n(0)
        {
            _array = new T[_n];
        }

        Array(const unsigned int &n) : _n(n)
        {
            _array = new T[_n];
        }

        Array(const Array &arg)
        {
            _n = arg._n;
            _array = new T[_n];
            *this = arg;  
        }

        ~Array()
        {
            delete []_array;
        }

        Array &operator=(const Array &arg)
        {
            _n = arg._n;
            if (_array)
                delete []_array;
            _array = new T(_n);
            for (size_t i = 0; i < _n; i++)
                _array[i] = arg._array[i];
            return *this;           
        }

        T &operator[](size_t i)
        {
            if (i > _n || !_array[i])
                throw TooHighIndex();
            return (_array[i]);
        }

        size_t  size()
        {
            return (_n);
        }
    protected:

    private:
        T               *_array;
        unsigned int    _n;
};