#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_size(0)
{
	m_elements = new T[m_size];
}

template <typename T>
Array<T>::Array(unsigned int n) : m_size(n)
{
	m_elements = new T[m_size];
}

template <typename T>
Array<T>::Array(const Array& toCopy): m_size(toCopy.m_size)
{
	m_elements = new T[m_size];
	for(unsigned int i = 0; i < m_size; i++)
		m_elements[i] = toCopy.m_elements[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& toCopy)
{
	if (this != &toCopy)
	{
		delete m_elements;
		m_size = toCopy.m_size;
		m_elements = new T[m_size];
		for(int i = 0; i < m_size; i++)
			m_elements[i] = toCopy.m_elements[i];
	}
	return(*this);
}

template <typename T>
Array<T>::~Array() { delete [] m_elements; }

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	return ((index >= m_size) ? throw OutOfTheRangeException() : (*(m_elements +index)));
}

template <typename T>
unsigned int Array<T>::size() const { return(m_size); }

template <typename T>
const char* Array<T>::OutOfTheRangeException::what() const throw()
{
	return("[ERROR] The index is out of the range!");
}