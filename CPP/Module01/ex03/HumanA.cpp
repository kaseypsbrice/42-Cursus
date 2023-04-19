#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : weapon(_weapon)
{
    this->name = _name;
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    if (!weapon.getType().empty())
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}