#include "aAnimal.hpp"

aAnimal::aAnimal()
{
    m_type = "aAnimal";
    std::cout << "\33[1;32mDefault constructor called for aAnimal\33[0;m" << std::endl;
}

aAnimal::aAnimal(const aAnimal& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for aAnimal" << std::endl;
}

aAnimal& aAnimal::operator=(const aAnimal& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    std::cout << "Copy assignment called for aAnimal" << std::endl;
    return (*this);
}

aAnimal::~aAnimal()
{
    std::cout << "\33[1;31mDestructor called for aAnimal\33[0;m" << std::endl;
}

void aAnimal::makeSound() const
{
    std::cout << "\33[1;29maAnimal makes aanimal-like sounds\33[1;29m" << std::endl;
}

std::string aAnimal::getType( void ) const { return(m_type); }