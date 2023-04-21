#include "ClapTrap.hpp"

int main()
{
    { // Scenario 1: Using up all of their energy.
        ClapTrap claptrap;
        ClapTrap otherClapTrap("Clappy");

        for (int i = 0; i < 8; i++)
        {
            otherClapTrap.attack("enemy");
        }
        otherClapTrap.beRepaired(2);
        otherClapTrap.attack("enemy");
        otherClapTrap.attack("enemy");
        otherClapTrap.beRepaired(1);
        return (EXIT_SUCCESS);   
    } // Result: hit once after repair then runs out of energyPoints

    /*
    { // Scenario 2: Running out of hitPoints. (Also shows use of copy assignment constructor)
        ClapTrap namedClapTrap("Clappy");
        ClapTrap claptrap;

        claptrap = namedClapTrap;
        claptrap.attack("you");
        claptrap.takeDamage(10);
        claptrap.takeDamage(1);
        claptrap.attack("you");
        return (EXIT_SUCCESS);
    } // Result: attacks you (-1 energyPoint), takes 10 damage, 
    // taking additional damage isn't possible and no longer
    // has any hitPoints left to attack you.
    */

   /*
   { // Shows use of copy constructor
        ClapTrap original("Daniel");
        ClapTrap thecopy(original);

        thecopy.attack("you");
        thecopy.takeDamage(3);
        thecopy.beRepaired(2);
        return (EXIT_SUCCESS);
   }
   */
}