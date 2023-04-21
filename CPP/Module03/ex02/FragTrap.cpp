#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "\033[90mFragTrap Default constructor called\e[0m" << std::endl;
    this->name = "DefaultFrag";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    return ;
}

FragTrap::FragTrap(std::string str)
{
    std::cout << "\033[90mFragTrap Parameterised constructor called\e[0m" << std::endl;
    this->name = str;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    return ;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "\033[90mFragTrap Copy constructor called\e[0m" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "\033[90mFragTrap Copy assignment operator called\e[0m" << std::endl;
    this->name = other.getName();
    this->hitPoints = other.getHitPoints();
    this->energyPoints = other.getEnergyPoints();
    this->attackDamage = other.getAttackDamage();
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " says high five!!" << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[90mFragTrap Destructor called\e[0m" << std::endl;
}