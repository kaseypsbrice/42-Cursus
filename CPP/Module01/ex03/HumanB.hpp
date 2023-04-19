#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    private:
        Weapon      *weapon;
        std::string name;
    public:
        HumanB(std::string _name);
        ~HumanB();
        void        setWeapon(Weapon& _weapon);
        void        attack();
};

#endif