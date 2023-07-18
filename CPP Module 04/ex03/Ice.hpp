#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& );
        Ice& operator=(const Ice& );
        ~Ice();
        
        Ice* clone() const; // or ice* return type 
        void use(ICharacter& target);
};

#endif