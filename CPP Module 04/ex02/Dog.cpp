#include "Dog.hpp"

Dog::Dog()
{
    m_type = "Dog";
    m_brain = new Brain();
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

Dog::Dog(const Dog& toCopy)
{
    m_brain = new Brain(*toCopy.m_brain);
    m_type = toCopy.m_type;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Dog& Dog::operator=(const Dog& toCopy)
{
    if (this != &toCopy)
    {
        m_type = toCopy.m_type;
        delete m_brain;
        m_brain = new Brain(*toCopy.m_brain);
        m_type = toCopy.m_type;
    }
    std::cout << "Copy assignment called for " << m_type << std::endl;
    return(*this);
}

Dog::~Dog()
{
    delete m_brain;
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << m_type << "\33[1;29m says Woof Woof\33[1;29m" << std::endl;
}