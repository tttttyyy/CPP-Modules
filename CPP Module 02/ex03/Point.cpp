#include "Point.hpp"

Point::Point()
: x(Fixed(0)), y(Fixed(0))
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float a, const float b)
: x(Fixed(a)), y(Fixed(b))
{
	// std::cout << "Parameter constructor called" << std::endl;
}

Point::Point(const float a)
: x(Fixed(a)), y(Fixed(0))
{
	// std::cout << "Parameter constructor called" << std::endl;
}

Point::Point ( const Fixed &toCopy )//copy constructor
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Point& Point::operator= ( const Point &toCopy )//copy assignment
{
	// std::cout << "Copy assignment operator called " << std::endl;
	if (this != &toCopy)
	{
		(Fixed)this->x = toCopy.getX();
		(Fixed)this->y = toCopy.getY();
	}
	return (*this);
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX( void ) const
{
	return(x);
}

Fixed Point::getY( void ) const
{
	return(y);
}