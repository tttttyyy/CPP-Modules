#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_size(0)
{
	m_elements = new T[m_size];
}

Array<T>::Array(unsigned int n) : m_size(n)
{
	m_elements = new T[m_size];
}

Array<T>::Array(const Array& toCopy): m_size(toCopy.m_size)
{
	m_elements = new T[m_size];
	for(int i = 0; i < m_size; i++)
		m_elements[i] = toCopy.m_elements[i];
}

Array& Array<T>::operator=(const Array& toCopy)
{
	if (this != &toCopy)
	{
		delete m_elements
		m_elements = new T[m_size];
		for(int i = 0; i < m_size; i++)
			m_elements[i] = toCopy.m_elements[i];
	}
}

Array<T>::~Array() { delete [] m_elements;}