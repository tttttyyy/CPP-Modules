#include "Animal.hpp"

Animal::Animal()
{
    m_type = "Animal";
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

Animal::Animal(const Animal& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Animal& Animal::operator=(const Animal& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    std::cout << "Copy assignment called for " << m_type << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\33[1;31mDestructor called for\33[0;m" << m_type << std::endl;
}

void Animal::makeSound() const
{
    std::cout << m_type << "\33[1;29m makes animal-like sounds\33[1;29m" << std::endl;
}

std::string Animal::getType( void ) const { return(m_type); }