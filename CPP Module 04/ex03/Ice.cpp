#includee "Ice.hpp"

Ice::Ice()
{
    m_type = "ice";
}

Ice::Ice(const Ice& toCopy )
{
    *this = toCopy;
    std::cout << "Copy constructor called for " << m_type << std::endl;
}

Ice& Ice::operator=(const Ice& toCopy )
{
    if (this != &toCopy)
        m_type = toCopy.m_type;
    std::cout << "Copy assignment called for " << m_type << std::endl;
}

Ice::~Ice()
{
    std::cout << "\33[1;31mDestructor called for \33[0;m" << m_type << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at bob *" << std::endl;
}