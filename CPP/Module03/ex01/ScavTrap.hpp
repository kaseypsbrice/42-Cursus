#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(void);
	    ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap& other);
        ~ScavTrap();

        void        attack(const std::string& target);

        // NEW // ScavTrap specific function announcing it's in Gate Keeper mode.
        void        guardGate(void);
};

#endif