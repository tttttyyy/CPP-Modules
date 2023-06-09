#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float);
		Point(const float, const float);//ymm floating point
		~Point();
		Point ( Fixed const& );//copy constructor
		Point& operator= ( const Point & );//copy assignment
		Fixed getX( void ) const;
		Fixed getY( void ) const;
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif