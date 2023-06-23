#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &weapon);
	private:
		std::string m_name;
		Weapon *m_weapon;
};

#endif