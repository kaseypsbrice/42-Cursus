#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap test1("test1");

	test1.attack("me");
	test1.beRepaired(1);
	test1.takeDamage(7);
	test1.beRepaired(8);
	test1.takeDamage(18);

	std::cout << "--------------------------------------" << std::endl;

	ScavTrap test2("test2");

	test2.attack("you");
	test2.takeDamage(2);
	test2.beRepaired(1);
	test2.takeDamage(7);
	test2.beRepaired(8);
	test2.takeDamage(18);
	test2.guardGate();

	std::cout << "--------------------------------------" << std::endl;

	FragTrap test3("test3");

	test3.attack("them");
	test3.takeDamage(2);
	test3.beRepaired(1);
	test3.takeDamage(7);
	test3.beRepaired(8);
	test3.takeDamage(18);
	test3.highFivesGuys();

	std::cout << "--------------------------------------" << std::endl;

	FragTrap test4;
	test4 = test3;

	test3.attack("you");
	test3.takeDamage(2);
	test3.beRepaired(1);
	test3.takeDamage(7);
	test3.beRepaired(8);
	test3.takeDamage(18);
	test3.highFivesGuys();
	return (0);
}