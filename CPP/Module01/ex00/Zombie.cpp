#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->z_name = name;
}
// Initializes the z_name data member of the Zombie object with the given string.
// AKA It names a zombie :P

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->z_name << " has been destroyed." << std::endl;
}
// The destructor outputs a message to the console when a Zombie object is destroyed. 
// It uses the z_name data member to print the name of the Zombie object that is being destroyed.

void	Zombie::announce(void)
{
	std::cout << this->z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
// Will output the name of the zombie followed by the string.