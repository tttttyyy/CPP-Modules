#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
     public:
        FragTrap( void );
        FragTrap(std::string);
        FragTrap(const FragTrap&);
        FragTrap& operator=(const FragTrap& toCopy);
        ~FragTrap( void );
        
        void    highFivesGuys( void );
};

#endif