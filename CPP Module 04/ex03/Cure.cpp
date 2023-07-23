#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure( const Cure& toCopy )
{
    *this = toCopy;
    // std::cout << "Copy constructor called for " << m_type << std::endl;
}

Cure& Cure::operator=( const Cure& toCopy )
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    // std::cout << "Copy assignment called for " << m_type << std::endl;
    return(*this);
}

Cure::~Cure()
{
    // std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

Cure* Cure::clone() const 
{
    return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}