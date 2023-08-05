#ifndef	ARRAY_HPP
#define	ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		unsigned int size() const;
	private:
		T *m_elements;
		unsigned int m_size;
}

#endif