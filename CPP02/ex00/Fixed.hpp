#ifndef FIXED_HPP
#define FIXED_HPP

//--------------------------------------------------------------------------//
//	- 						  - INCLUDES -								-	//
//--------------------------------------------------------------------------//

# include <iostream>

//--------------------------------------------------------------------------//
//	 							- CLASS -									//
//--------------------------------------------------------------------------//

class Fixed
{
//-------------------------------------------------------------------PRIVATE//
private:
                           // - VARIABLES - //
        int                 _integer;
        static const int    _bitStock = 8;

                           // - FUNCTIONS - //

//--------------------------------------------------------------------PUBLIC//
public:
                           // - VARIABLES - //

                           // - FUNCTIONS - //

    // Constructors
        Fixed();
        Fixed(Fixed &fixed);
        ~Fixed();

    // Operators
        Fixed &operator=(const Fixed &fixed);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif