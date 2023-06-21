#include "Zombie.hpp"

int main()
{
	Zombie *array = zombieHorde(3, "kuku");
	for (int i = 0; i < 3; i++)
		array[i].announce();
	delete[] array;
	return (0);
}