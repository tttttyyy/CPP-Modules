#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "\033[32m" << "Zombie is created" << "\033[0m" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << "\033[31m" << m_name << ": is destroyed" << "\033[0m" << std::endl;
}

void Zombie::SetName(std::string name)
{
	m_name = name;	
}

void Zombie::announce()
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}