#include "Serializer.hpp"

int main()
{
	Data hero = {0, 1};

	uintptr_t ser = Serializer::serialize(&hero);
	std::cout << ser << std::endl;
	Data *deser = Serializer::deserialize(ser);
	std::cout << deser << std::endl;
	if (&hero == deser)
		std::cout << "\33[1;32mSuccess!\033[0m" << std::endl;
	else
		std::cout << "\33[1;31m[ERROR] Pointers do not match!\033[0m" << std::endl;

}