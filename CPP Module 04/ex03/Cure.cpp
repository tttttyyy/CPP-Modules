#include "Cure.hpp"

Cure::Cure()
{
    m_type = "cure";
}

Cure::Cure( const Cure& toCopy )
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Cure& Cure::operator=( const Cure& toCopy )
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    std::cout << "Copy assignment called for " << m_type << std::endl;
}

Cure::~Cure()
{
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

AMateria* Cure::clone() const // or Cure* return type 
{
    return(new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals bob's wounds *" << std::endl;
}