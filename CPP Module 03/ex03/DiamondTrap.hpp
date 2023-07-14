#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class ScavTrap ;

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap( void );
        DiamondTrap( std::string );
        DiamondTrap(const DiamondTrap&);
        DiamondTrap& operator=(const DiamondTrap&);
        ~DiamondTrap();

        using ScavTrap::attack;
        void whoAmI();
        
    private:
        std::string m_name;
        using   FragTrap::m_hitPoints;
        using   ScavTrap::m_energyPoints;
        using   FragTrap::m_attackDamage;
};

#endif