#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "\33[1;32mDefault constructor called for FragTrap \33[0;m" << m_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    m_name = name;
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "\33[1;32mParameter constructor called for FragTrap \33[0;m" << m_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for FragTrap " << m_name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "\33[1;31mDestructor called for FragTrap \33[0;m" << m_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& toCopy)
{
    if (this != &toCopy)
    {
        m_name = toCopy.m_name;
        m_hitPoints = toCopy.m_hitPoints;
        m_energyPoints = toCopy.m_energyPoints;
        m_attackDamage = toCopy.m_attackDamage;
    }
	std::cout << "Copy assignment operator called for FragTrap " << m_name << std::endl;
    return(*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "\33[1;36mFragTrap \033[0m" << m_name << "\33[1;36m says \"High Five Guys!\".\033[0m" << std::endl;
}