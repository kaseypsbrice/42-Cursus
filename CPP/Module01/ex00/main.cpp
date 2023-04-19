#include "Zombie.hpp"

int main( void )
{
    std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie zomb1(name);
    
    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie *zomb2 = newZombie(name);
    zomb2->announce();
    delete zomb2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("rando");
    return 0;
}