#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) : m_type(type) {}

std::string const & AMateria::getType() const { return(m_type); }

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMatreia's use function is used on " << target.getName() << std::endl;
}