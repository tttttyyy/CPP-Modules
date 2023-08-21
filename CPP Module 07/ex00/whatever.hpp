#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename what> void swap(what &a, what &b)
{
	what c = a;
	a = b;
	b = c;
}

template <typename what> what min(const what &a, const what &b)
{
	return ((a >= b) ? b : a);
}

template <typename what> what max(const what &a, const what &b)
{
	return ((a <= b) ? b : a);
}
class Awesome
{
public:
Awesome(void) : _n(0) {}
Awesome( int n ) : _n( n ) {}
Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
int get_n() const { return _n; }
private:
int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
#endif