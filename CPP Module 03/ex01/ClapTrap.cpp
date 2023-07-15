#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("noName"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "\33[1;32mDefault constructor called for ClapTrap \33[0;m" << m_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "\33[1;32mParameter constructor called for ClapTrap \33[0;m" << m_name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\33[1;31mDestructor called for ClapTrap \33[0;m" << m_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) //copy constructor
{
    *this = toCopy;
    std::cout << "Copy constructor called for ClapTrap " << m_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &toCopy) //copy assignment
{
    if (this != &toCopy)
    {
        this->m_name = toCopy.m_name;
        this->m_hitPoints = toCopy.m_hitPoints;
        this->m_energyPoints = toCopy.m_energyPoints;
        this->m_attackDamage = toCopy.m_attackDamage;
    }
    std::cout << "Copy assignment operator called for ClapTrap" << m_name << std::endl;
	return (*this);
}

bool ClapTrap::operator!=(ClapTrap const& toCompare)
{
    if (this->m_name != toCompare.m_name
    ||  this->m_hitPoints != toCompare.m_hitPoints
    ||  this->m_energyPoints != toCompare.m_energyPoints
    ||  this->m_attackDamage != toCompare.m_attackDamage)
		return (true);
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
    if (m_energyPoints < 1 || m_hitPoints < 1)
    {
        std::cout << "\033[31mClapTrap " << m_name << " has no either energy points or hit points for attack\033[0m" << std::endl;
        return ;
    }
    std::cout << "\33[1;33mClapTrap \033[0m" << m_name << "\33[1;33m attacks " << target << ", causing " << m_attackDamage << " points of damage!\033[0m" << std::endl;
    --m_energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hitPoints <= amount)
    {
        m_hitPoints = 0;
        std::cout << "ClapTrap " << m_name << "\33[1;31m was killed!\033[0m" << std::endl;
		return ;
    }
    m_hitPoints -= amount;
    std::cout << "\33[1;31mClapTrap \033[0m" << m_name << "\33[1;31m got hit " << amount << " times by an enemy, current hit points: \033[0m" << m_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!m_energyPoints)
    {
        std::cout << "\33[1;34mClapTrap \033[0m" << m_name << "\33[1;34m has no energy points to repair!" << std::endl;
        return ;
    }
    m_hitPoints += amount;
    --m_energyPoints;
    std::cout << "\33[1;34mClapTrap \033[0m" << m_name << "\33[1;34m got repaired by " << amount << " points!" << std::endl;
}
// std::string ClapTrap::getName(void) const { return (m_name); }
// void ClapTrap::setName(std::string const name) { m_name = name; }
// int ClapTrap::getHit(void) const { return (m_hitPoints); }
// void ClapTrap::setHit(int const hitPoints) { m_hitPoints = hitPoints; }
// int ClapTrap::getEnergy(void) const { return (m_energyPoints); }
// void ClapTrap::setEnergy(int const energyPoints) { m_energyPoints = energyPoints; }
// int ClapTrap::getAttack(void) const { return (m_attackDamage); }
// void ClapTrap::setAttack(int const attackDamage) { m_attackDamage = attackDamage; }