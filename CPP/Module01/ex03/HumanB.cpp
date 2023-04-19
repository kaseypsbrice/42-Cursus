#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
    weapon = NULL;
    this->name = _name;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon& _weapon)
{
    this->weapon = &_weapon;
}

void    HumanB::attack()
{
    if (!weapon->getType().empty())
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}