#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "\33[1;32mDefault constructor called for ScavTrap \33[0;m" << m_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    m_name = name;
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "\33[1;32mDefault constructor called for ScavTrap \33[0;m" << m_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\33[1;31mDestructor called for ScavTrap \33[0;m" << m_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& toCopy)
{
    if (*this != toCopy)
    {
        m_name = toCopy.m_name;
        m_hitPoints = toCopy.m_hitPoints;
        m_energyPoints = toCopy.m_energyPoints;
        m_attackDamage = toCopy.m_attackDamage;
    }
    return(*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (m_energyPoints < 1 || m_hitPoints < 1)
    {
        std::cout << "\033[31mScavTrap " << m_name << " has no either energy points or hit points for attack\033[0m" << std::endl;
        return ;
    }
    std::cout << "\33[1;33mScavTrap \033[0m" << m_name << "\33[1;33m attacks " << target << ", causing " << m_attackDamage << " points of damage!\033[0m" << std::endl;
    --m_energyPoints;
}

void ScavTrap::guardGate()
{
    std::cout << "\33[1;36mScavTrap \033[0m" << m_name << "\33[1;36m is now in Gate keeper mode.\033[0m" << std::endl;
}