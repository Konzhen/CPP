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
        ~Fixed();

        Fixed& operator=(const Fixed &fixed);
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);
        bool operator<(const Fixed& comp) const;
        bool operator>(const Fixed& comp) const;
        bool operator<=(const Fixed& comp) const;
        bool operator>=(const Fixed& comp) const;
        bool operator==(const Fixed& comp) const;
        bool operator!=(const Fixed& comp) const;    

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void ) const;
        int     toInt(void ) const;

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif