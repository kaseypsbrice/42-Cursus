#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat(void);

        void    makeSound(void) const;
        Brain   *getBrain() const;
    private:
        Brain *brain;
};

#endif