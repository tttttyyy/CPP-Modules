#include "Dog.hpp"

Dog::Dog()
{
    m_type = "Dog";
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

Dog::Dog(const Dog& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Dog& Dog::operator=(const Dog& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << m_type << "\33[1;29m says Woof Woof\33[1;29m" << std::endl;
}