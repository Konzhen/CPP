#include "Fixed.hpp"

Fixed::Fixed(): _n(0)
{

}

Fixed::Fixed(const int n)
{
	_n = n << _exponent;
}

Fixed::Fixed(const float n)
{
	_n = roundf(n * (1 << _exponent));
}

Fixed::Fixed(Fixed const &fixed)
{
	this->_n = fixed.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	this->_n = fixed.getRawBits();

	return (*this);
}

Fixed Fixed::operator+(Fixed const &fixed)
{
	Fixed item(this->toFloat() + fixed.toFloat());

	return (item);
}

Fixed Fixed::operator-(Fixed const &fixed)
{
	Fixed item(this->toFloat() - fixed.toFloat());

	return (item);
}

Fixed Fixed::operator*(Fixed const &fixed)
{
	Fixed item(this->toFloat() * fixed.toFloat());

	return (item);
}

Fixed Fixed::operator/(Fixed const &fixed)
{
	Fixed item(this->toFloat() / fixed.toFloat());

	return (item);
}

bool Fixed::operator<(const Fixed& comp) const
{
	return (_n < comp._n);
}

bool Fixed::operator>(const Fixed& comp) const
{
	return (_n > comp._n);
}

bool Fixed::operator<=(const Fixed& comp) const
{
	return (_n <= comp._n);
}

bool Fixed::operator>=(const Fixed& comp) const
{
	return (_n >= comp._n);
}

bool Fixed::operator==(const Fixed& comp) const
{
	return (_n == comp._n);
}

bool Fixed::operator!=(const Fixed& comp) const
{
	return (_n != comp._n);
}

Fixed &Fixed::operator++()
{
	_n++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_n--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_n++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_n--;
	return (tmp);
}

int Fixed::getRawBits() const
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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	Fixed	acpy = a;
	Fixed	bcpy = b;
	if (acpy < bcpy)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	Fixed	acpy = a;
	Fixed	bcpy = b;
	if (acpy > bcpy)
		return (a);
	return (b);
}


std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}