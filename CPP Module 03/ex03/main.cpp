#include "DiamondTrap.hpp"
int main()
{
	DiamondTrap frank("Frank");
	ScavTrap scav("SSSS");

    // Call member functions to test
    scav.attack("heyyy");
    frank.attack("enemy");
    frank.takeDamage(50);
    frank.beRepaired(15);
    frank.highFivesGuys();
    frank.guardGate();
    frank.whoAmI();
    return (0);
}