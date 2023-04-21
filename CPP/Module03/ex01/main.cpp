#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    { // When they run out of points, you can see their different stats.
        ClapTrap claptrap("ClapTrap");
        ScavTrap scavtrap("ScavTrap");

        for (int i = 0; i < 11; i++)
            claptrap.attack("you");
        claptrap.beRepaired(1);
        claptrap.takeDamage(10);
        claptrap.takeDamage(2);
        std::cout << "---------------------------------------" << std::endl;
        for (int j = 0; j < 50; j++)
            scavtrap.attack("you");
        scavtrap.beRepaired(1);
        scavtrap.takeDamage(100);
        scavtrap.takeDamage(1);
        scavtrap.guardGate();
        std::cout << "---------------------------------------" << std::endl;
        return (EXIT_SUCCESS);
    }
}
// The program starts by building a ClapTrap because the ScavTrap class
// is dependant on the ClapTrap class as it inherits from the class.
//
// ScavTrap's destructor is called before ClapTrap's because of the same
// reason. To prevent any possible errors due to references
// to memory, the inner class will be destroyed before the outer class.
// Any dependancies between the classes will be resolved before the destruction
// of the objects this way.