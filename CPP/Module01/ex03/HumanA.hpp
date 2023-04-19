#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
    private:
        Weapon&     weapon;
        std::string name;
    public:
        HumanA(std::string _name, Weapon& _weapon);
        ~HumanA();
        void        attack();
};

#endif