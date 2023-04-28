#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        virtual ~WrongAnimal();
        // When used as a base class, it's recommended that the destructor is declared 
        // as a virtual destructor. Although it technically doesn't need to be,
        // it ensures that the correct destructor is called.

        std::string getType(void) const;
        void    makeSound(void) const;
};

#endif