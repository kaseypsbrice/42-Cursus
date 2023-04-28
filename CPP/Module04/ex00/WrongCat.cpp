#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->WrongAnimal::operator=(copy);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << type << " destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "*Wrong-meow*" << std::endl;
}