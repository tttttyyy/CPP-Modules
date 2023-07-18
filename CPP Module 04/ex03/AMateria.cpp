#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : m_type(type) {}

std::string const & AMateria::getType() const { return(m_type); }

// AMateria* AMateria::clone() const { return(new AMateria()); }