#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    m_type = "WrongCat";
    std::cout << "\33[1;32mDefault constructor called for \33[0;m" << m_type << std::endl;
}

WrongCat::WrongCat(const WrongCat& toCopy)
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& toCopy)
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << m_type << "\33[1;29m says Meow Meow\33[1;29m" << std::endl;
}