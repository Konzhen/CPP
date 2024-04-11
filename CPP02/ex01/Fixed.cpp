#include "Fixed.hpp"

Fixed::Fixed(): _n(0)
{

}

Fixed::Fixed(const int n)
{
	_n = n << _exponent;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	_n = roundf(n * (1 << _exponent));
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = fixed.getRawBits();

	return (*this);
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = fixed.getRawBits();
}

int	Fixed::getRawBits(void) const
{
	return (_n);
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_n / (1 << _exponent));
}

int	Fixed::toInt(void) const
{
	return (_n >> _exponent);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}