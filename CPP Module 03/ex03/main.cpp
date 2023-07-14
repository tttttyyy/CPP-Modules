#include "DiamondTrap.hpp"
int main()
{
	DiamondTrap frank("Frank");

    // Call member functions to test
    frank.attack("enemy");
    frank.takeDamage(50);
    frank.beRepaired(15);
    frank.highFivesGuys();
    frank.whoAmI();
    return (0);
}