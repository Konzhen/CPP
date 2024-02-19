 #ifndef PMERGEME_HPP
#define PMERGEME_HPP

//--------------------------------------------------------------------------//
//    -                           - INCLUDES -                                -    //
//--------------------------------------------------------------------------//
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>
# include <sstream>
# include <limits.h>
# include <cstdlib>

//--------------------------------------------------------------------------//
//                                 - CLASS -                                    //
//--------------------------------------------------------------------------//
typedef std::vector<int>                    int_vector;

template<typename Container>

class PmergeMe
{
//--PUBLIC------------------------------------------------------------------//
                           // - DEFINES - //
    public:
    typedef typename Container::value_type      value_type;
    typedef typename Container::size_type       size_type;                       
    typedef std::pair <value_type, value_type>  type_pair;
    typedef std::vector <type_pair>             pair_vector;



//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
    Container   data;
    value_type  last;
    double      time;
                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions
    int         binary_search(int target);
    int         ft_stoa(const char *str);
    bool        is_number(const std::string& s);

//--PROTECTED---------------------------------------------------------------//
    protected:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions
    public:
                           // - FUNCTIONS - //

    // Constructor & Destructors
    PmergeMe();
    explicit PmergeMe(char **data);
    PmergeMe(const PmergeMe &data);
    ~PmergeMe();

    // Operators
    PmergeMe &operator=(const PmergeMe &data);

    // Getters & Setters


    // Member Functions
    void        sort();
    void        print_data() const;
    void        print_time() const;
    void        sort_pairs(pair_vector &pairs);
    int_vector  indexing(size_t n);
    pair_vector pairing(Container &data);


};

#endif