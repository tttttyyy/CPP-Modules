#include "Cat.hpp"

Cat::Cat()
{
    m_type = "Cat";
    m_brain = new Brain();
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

Cat::Cat(const Cat& toCopy)
{
    m_brain = new Brain(*toCopy.m_brain);
    m_type = toCopy.m_type;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Cat& Cat::operator=(const Cat& toCopy)
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

Cat::~Cat()
{
    delete m_brain;
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

void Cat::makeSound() const
{
    std::cout << m_type << "\33[1;29m says Meow Meow\33[1;29m" << std::endl;
}