#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal();
        // 'virtual' ensures that when a derived class object is destroyed through a
        // pointer to the base class, the destructor of the derived class will be called first,
        // followed by the base class.
        // This allows all resources allocated by the derived class to be properly cleaned before
        // the base class destructor is called. If it wasn't declared as virutal, the base class
        // destructor would be called before the derived class's resources are released properly.

        std::string getType(void) const;
        virtual void    makeSound(void) const;
        // 'virtual' keyword here indicates that the function is polymorphic.
        // It can be overridden by a function with the same name in a derived class.
};

#endif