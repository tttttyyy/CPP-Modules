#include "Animal.hpp"

Animal::Animal()
{
    m_type = "Animal";
    std::cout << "\33[1;32mDefault constructor called for Animal\33[0;m" << std::endl;
}

Animal::Animal(const Animal& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    std::cout << "Copy assignment called for Animal" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\33[1;31mDestructor called for Animal\33[0;m" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "\33[1;29mAnimal makes animal-like sounds\33[1;29m" << std::endl;
}

std::string Animal::getType( void ) const { return(m_type); }