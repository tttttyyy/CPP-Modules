#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_fixedPoint = 0;
}

Fixed::Fixed(const int fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	m_fixedPoint = fixedPoint << m_fractionalBits;
}

Fixed::Fixed(const float fixedPoint)
{
	std::cout << "Float constructor called" << std::endl;
	m_fixedPoint = roundf(fixedPoint * (1 << m_fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed& Fixed::operator= ( const Fixed &toCopy)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &toCopy)
		this->setRawBits(toCopy.getRawBits());
	return (*this);
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(m_fixedPoint);
}

void Fixed::setRawBits( int const raw ) { m_fixedPoint = raw; }

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(m_fixedPoint) / (1 << m_fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (m_fixedPoint >> m_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
    os << fix.toFloat();
    return os;
}

bool Fixed::operator>(Fixed const& obj)
{
	if (this->getRawBits() > obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const& obj)
{
	if (this->getRawBits() < obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const& obj)
{
	if (this->getRawBits() <= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const& obj)
{
	if (this->getRawBits() >= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const& obj)
{
	if (this->getRawBits() == obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const& obj)
{
	if (this->getRawBits() != obj.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const& obj)
{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const& obj)
{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const& obj)
{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const& obj)
{
	return (this->toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++(void) //prefix
{
	++m_fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed tmp = *this;
	++m_fixedPoint;
	return (tmp);
}

Fixed& Fixed::operator--(void) //prefix
{
	--m_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed tmp = *this;
	--m_fixedPoint;
	return (tmp);
}

Fixed& min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
// static Fixed& min(const Fixed& a, const Fixed& b);
// static Fixed& max(Fixed& a, Fixed& b);
// static Fixed& max(const Fixed& a, const Fixed& b);