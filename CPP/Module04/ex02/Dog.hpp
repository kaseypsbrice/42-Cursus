#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog(void);

        void    makeSound(void) const;
        Brain   *getBrain(void) const;
    private:
        Brain *brain;
};

#endif