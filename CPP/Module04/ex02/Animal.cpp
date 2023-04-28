#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << type << " default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = copy.getType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return(this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << "*Animal sounds*" << std::endl;
}