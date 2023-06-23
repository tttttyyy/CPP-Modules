#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string);
		~Weapon();
		const std::string& getType();
		void setType(std::string);
	private:
		std::string	m_type;
};

#endif