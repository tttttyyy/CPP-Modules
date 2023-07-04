#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( const int );
		Fixed( const float );
		~Fixed();
		Fixed ( const Fixed & );//copy constructor
		Fixed& operator= ( const Fixed & );//copy assignment
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator>(Fixed const& ); 
		bool operator<(Fixed const& );
		bool operator<=(Fixed const& );
		bool operator>=(Fixed const& );
		bool operator==(Fixed const& );
		bool operator!=(Fixed const& );
		Fixed operator+(Fixed const& );
		Fixed operator-(Fixed const& );
		Fixed operator*(Fixed const& );
		Fixed operator/(Fixed const& );
		Fixed& operator++( void ); //prefix
		Fixed operator++(int); //postfix
		Fixed& operator--( void ); //prefix
		Fixed operator--(int); //postfix
		static Fixed& min(Fixed&, Fixed&);
		static Fixed& min(const Fixed&, const Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static Fixed& max(const Fixed&, const Fixed&);


	private:
		int m_fixedPoint;
		static const int m_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif