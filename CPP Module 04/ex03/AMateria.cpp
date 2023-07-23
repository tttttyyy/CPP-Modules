#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : m_type(type) {}

AMateria::AMateria( const AMateria & toCopy ) { *this = toCopy; }

AMateria& AMateria::operator=( const AMateria & toCopy )
{
	if(this != &toCopy )
		m_type = toCopy.m_type;
	return(*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return(m_type); }

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMatreia's use function is used on " << target.getName() << std::endl;
}