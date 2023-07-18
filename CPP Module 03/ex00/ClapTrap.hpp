#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string);
        ClapTrap(const ClapTrap &); //copy constructor
        ClapTrap& operator=(const ClapTrap &); //copy assignment
        bool operator!=(ClapTrap const& );
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string m_name;
        unsigned int m_hitPoints;
        unsigned int m_energyPoints;
        unsigned int m_attackDamage;
};

#endif