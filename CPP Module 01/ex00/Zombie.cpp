#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
}
Zombie::~Zombie()
{
	std::cout << "\033[32m" << m_name << ": is destroyed" << "\033[0m" << std::endl;
}

void Zombie::announce()
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}