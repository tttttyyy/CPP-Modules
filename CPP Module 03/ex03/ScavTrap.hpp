#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap&);
        
        void attack(const std::string& target);
        void guardGate();
};

#endif