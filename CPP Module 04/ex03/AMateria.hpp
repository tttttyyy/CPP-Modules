#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "iostream"

class AMateria
{
    public:
        AMateria();
		AMateria(const AMateria &);
        AMateria(std::string const & type);
		AMateria& operator=(const AMateria &);
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    protected:
        std::string m_type;
};

#endif