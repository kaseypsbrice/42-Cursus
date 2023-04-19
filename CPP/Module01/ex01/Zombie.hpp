#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string z_name;

	public:
		Zombie();
		~Zombie();
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	setName( std::string name );
};

Zombie*		zombieHorde( int N, std::string name );

#endif