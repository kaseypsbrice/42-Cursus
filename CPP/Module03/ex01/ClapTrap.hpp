#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap(void); // default constructor
	    ClapTrap(std::string name); // parameterised constructor
        ClapTrap(const ClapTrap &other); // copy constructor
        ClapTrap &operator=(const ClapTrap& other); // copy assignment operator
        ~ClapTrap(); // destructor

        // required public member functions
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        // 'get' functions
        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getAttackDamage(void) const;
        int         getEnergyPoints(void) const;
};

#endif