#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	SetName(std::string name);
		void	announce( void );

	private:
		std::string m_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif