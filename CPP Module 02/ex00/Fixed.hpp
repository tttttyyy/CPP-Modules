#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed ( const Fixed & );//copy constructor
		Fixed& operator= ( const Fixed & );//copy assignment
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int m_fixedPoint;
		static const int m_fractionalBits = 8;
};

#endif