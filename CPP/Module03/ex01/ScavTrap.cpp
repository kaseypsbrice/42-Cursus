#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "\033[90mScavTrap Default constructor called\e[0m" << std::endl;
    this->name = "DefaultScav";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(std::string str)
{
    std::cout << "\033[90mScavTrap Parameterised constructor called\e[0m" << std::endl;
    this->name = str;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "\033[90mScavTrap Copy constructor called\e[0m" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "\033[90mScavTrap Copy assignment operator called\e[0m" << std::endl;
    this->name = other.getName();
    this->hitPoints = other.getHitPoints();
    this->energyPoints = other.getEnergyPoints();
    this->attackDamage = other.getAttackDamage();
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << attackDamage << " points of damage." << std::endl;
        this->energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " has \033[0;36m" << this->hitPoints << " hitPoints\e[0m and \033[0;36m" << this->energyPoints 
                                                                        << " energyPoints\e[0m and cannot attack " << target << "!" << std::endl;
    }    
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
    return ;
}
// The newly added function for ex01.

ScavTrap::~ScavTrap()
{
    std::cout << "\033[90mScavTrap Destructor called\e[0m" << std::endl;
}