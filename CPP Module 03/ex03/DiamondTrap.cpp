#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    m_name = "noName";
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 30;
    std::cout << "\33[1;32mDefault constructor called for DiamondTrap \33[0;m" << m_name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap")
{
    m_name = name;
    ClapTrap::m_name = name + "_clap_trap";
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 30;
    std::cout << "\33[1;32mParameter constructor called for DiamondTrap \33[0;m" << m_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCopy) : ClapTrap(toCopy), FragTrap(toCopy), ScavTrap(toCopy)
{
    *this = toCopy;
    std::cout << "\33[1;32mCopy constructor called for DiamondTrap \33[0;m" << m_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& toCopy)
{
    if (*this != toCopy)
    {
        m_name = toCopy.m_name;
        m_hitPoints = toCopy.m_hitPoints;
        m_energyPoints = toCopy.m_energyPoints;
        m_attackDamage = toCopy.m_attackDamage;
    }
	std::cout << "Copy assignment operator called for DiamondTrap " << m_name << std::endl;
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\33[1;31mDestructor called for DiamondTrap \33[0;m" << m_name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name = " << m_name << std::endl;
    std::cout << "ClapTrap name = " << ClapTrap::m_name << std::endl;
}