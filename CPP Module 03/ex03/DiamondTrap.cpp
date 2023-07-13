#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    m_name = "noName";
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 30;
    std::cout << "\33[1;32mDefault constructor called for DiamondTrap \33[0;m" << m_name << std::endl;
}