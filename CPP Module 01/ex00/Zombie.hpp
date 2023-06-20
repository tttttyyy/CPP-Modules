#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
//m_name or name?
class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void		announce( void );

	private:
		std::string m_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif