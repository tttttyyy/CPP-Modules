#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& toCopy )
{
    *this = toCopy;
    // std::cout << "Copy constructor called for " << m_type << std::endl;
}

Ice& Ice::operator=(const Ice& toCopy )
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    // std::cout << "Copy assignment called for " << m_type << std::endl;
    return(*this);
}

Ice::~Ice()
{
    // std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

Ice* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}