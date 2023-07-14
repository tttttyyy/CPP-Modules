#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    m_type = "WrongAnimal";
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\33[1;31mDestructor called for WrongAnimal \33[0;m" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << m_type << "\33[1;29m makes Wronganimal-like sounds\33[1;29m" << std::endl;
}

std::string WrongAnimal::getType( void ) const { return(m_type); }