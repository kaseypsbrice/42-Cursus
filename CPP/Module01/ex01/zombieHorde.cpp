#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName( name );
	}
	return zombies;
}
// Loops through an array of zombies and names them all.
// Returns a pointer to the first element of the array.
// Deallocates in the main using delete[].