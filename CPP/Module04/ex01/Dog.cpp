#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    try {
        this->type = "Dog";
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation failed : " << e.what() << std::endl;
    }
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->brain = new Brain(*other.getBrain());
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << type << " copy operator called" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "*Woof*" << std::endl;
}

Brain   *Dog::getBrain(void) const
{
    return (this->brain);
}