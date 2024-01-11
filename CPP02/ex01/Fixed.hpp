#ifndef FIXED_HPP
#define FIXED_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>
# include <cmath>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Fixed
{
//-------------------------------------------------------------------PRIVATE//
    private:
    // - Variables - //
        int                 _n;
        static const int    _exponent = 8;

    // - Functions - //

//--------------------------------------------------------------------PUBLIC//
    public:
    // - Variables - //

    // - Functions - //
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(Fixed const &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void ) const;
        int     toInt(void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif