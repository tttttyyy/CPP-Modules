#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
     public:
        FragTrap( void );
        FragTrap(std::string);
        FragTrap(const FragTrap&);
        virtual ~FragTrap( void );
        FragTrap& operator=(const FragTrap& toCopy);
        void    highFivesGuys( void );
};

#endif