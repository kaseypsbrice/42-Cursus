#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "\033[90mClapTrap Default constructor called\e[0m" << std::endl;
    this->name = "";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    return ;
}

ClapTrap::ClapTrap(std::string str)
{
    std::cout << "\033[90mClapTrap Parameterised constructor called\e[0m" << std::endl;
    this->name = str;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "\033[90mClapTrap Copy constructor called\e[0m" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "\033[90mClapTrap Copy assignment operator called\e[0m" << std::endl;
    this->name = other.getName();
    this->hitPoints = other.getHitPoints();
    this->energyPoints = other.getEnergyPoints();
    this->attackDamage = other.getAttackDamage();
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->name);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->hitPoints);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->attackDamage);
}

int ClapTrap::getEnergyPoints(void) const
{
    return (this->energyPoints);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << attackDamage << " points of damage." << std::endl;
        this->energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has \033[0;36m" << this->hitPoints << " hitPoints\e[0m and \033[0;36m" << this->energyPoints 
                                                                        << " energyPoints\e[0m and cannot attack " << target << "!" << std::endl;
    }    
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " takes " << amount << " damage." << std::endl;
        this->hitPoints -= amount;
        if (this->hitPoints < 0)
            this->hitPoints = 0;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has \033[0;36m" << this->hitPoints << " hitPoints\e[0m and has nothing left to lose!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " was repaired for " << amount << " hit points." << std::endl;
        this->hitPoints += amount;
        if (this->hitPoints > 10)
            this->hitPoints = 10;
        this->energyPoints--;
    }
    else if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has \033[0;36m" << this->hitPoints << " hitPoints\e[0m and \033[0;36m" << this->energyPoints 
                                                                        << " energyPoints\e[0m and cannot be repaired!" << std::endl;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[90mClapTrap Destructor called\e[0m" << std::endl;
}