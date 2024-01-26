#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Deafult constructor called" << std::endl;
    value = 0;
}
// Default constructor

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
// Copy constructor

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
    return *this;
}
// Assignment operator

Fixed::Fixed(const int a)
{
    std::cout << "Int constructor called" << std::endl;
    value = (a << this->fractionalBits);
}
// Constant integer constructor

Fixed::Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
    value = std::roundf(a *(1 << fractionalBits));
}
// Constant float constructor

float   Fixed::toFloat( void ) const
{
    return ((value / (float)(1 << fractionalBits)));
}

int     Fixed::toInt( void ) const
{
    return (this->value >> this->fractionalBits);
}

int     Fixed::getRawBits(void) const
{
    return (this->value);
}

void    Fixed::setRawBits(int raw)
{
    this->value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
// Destructor

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}
// Insertion operator is overloaded to perform output of
// 'Fixed' objects using the '<<' operator. Uses toFloat() to
// get the float value of the object and outputs it to the
// terminal.