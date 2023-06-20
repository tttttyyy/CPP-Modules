#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie curr(name);
	curr.announce();
}