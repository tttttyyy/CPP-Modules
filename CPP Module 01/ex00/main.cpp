#include "Zombie.hpp"

int main()
{
	randomChump("stack");
	
	
	Zombie *b = newZombie("heap");
	b->announce();
	delete b;
	return (0);
}