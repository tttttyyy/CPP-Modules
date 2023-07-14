#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\33[1;32mDefault constructor called for Brain\33[0;m" << std::endl;
}

Brain::Brain(const Brain& toCopy)
{
    if (this != &toCopy)
    {
        for(int i = 0; i < 100; i++)      //not sure
            m_ideas[i] = toCopy.m_ideas[i];
    }
    std::cout << "Copy constructor called for Brain" << std::endl;
}

Brain::Brain& operator=(const Brain& toCopy)
{

}

Brain::~Brain()
{
    std::cout << "\33[1;31mDestructor called for Brain\33[0;m" << std::endl;
}