#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zomb(name);
	zomb.announce();
}
// Creates a zombie, names it, then announces itself.