#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
// Allocates memory for a new Zombie object on the heap.
// Returns a pointer to the newly created Zombie object.
// As defined in the subject file: It creates a zombie, names it, 
// and returns it so that you can use it outside of the function scope.