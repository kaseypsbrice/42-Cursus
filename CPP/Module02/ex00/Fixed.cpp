#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Deafult constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    value = other.getRawBits();
}
// Creates a new Fixed object by copying the value of
// another fixed object.

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignmenet operator called" << std::endl;
    value = other.getRawBits();
    return (*this);
}
// Sets the value of the current Fixed object to the value of
// another fixed object.

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}