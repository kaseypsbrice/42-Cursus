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

// Above is the same as the previous exercise.
// --------------- + --------------- + --------------- + ------ //
// Everything added for Ex02 as per the subject file.

// +---------------- Arithmetic Operators ----------------+ //
// Overloaded arithmetic operators for the 'Fixed' class.

Fixed   Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

// +---------------- Comparison Operators ----------------+ //
// Compares two 'Fixed' class instances and returns true or
// false depending on their values.

bool    Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

// +----------- Increment & Decrement Operators ----------+ //

Fixed   Fixed::operator++(int)
{
    Fixed   old = *this;
    this->value++;
    return (old);
}

Fixed   Fixed::operator--(int)
{
    Fixed   old = *this;
    this->value--;
    return (old);
}
// Returns a copy of the object before the increment or
// decrement operation is performed.

Fixed   Fixed::operator++(void)
{
    Fixed   &newf = *this;
    this->value++;
    return (newf);
}

Fixed   Fixed::operator--(void)
{
    Fixed   &newf = *this;
    this->value++;
    return (newf);
}
// Returns a reference to the object after the increment
// or decrement operation is performed.

// +---------------- Min - Max Functions ----------------+ //
// There are two versions of each function, one that takes
// non-const references and the other const. They return the
// minimum and maximum value between two 'Fixed' objects.
// Non-const versions allow for the returned reference to be
// used for assignment, the const versions do not.

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;    
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}