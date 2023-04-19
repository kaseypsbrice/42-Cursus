#include "Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->z_name << " has been destroyed." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->z_name = name;
}