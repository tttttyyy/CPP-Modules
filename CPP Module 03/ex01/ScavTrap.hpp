#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ~ScavTrap();
        void attack(const std::string& target);
        ScavTrap& operator=(const ScavTrap&);
        void guardGate();
};

#endif