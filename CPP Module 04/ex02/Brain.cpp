#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        m_ideas[i] = "noIdea";
    std::cout << "\33[1;32mDefault constructor called for Brain\33[0;m" << std::endl;
}

Brain::Brain(const Brain& toCopy)
{
    for(int i = 0; i < 100; i++)      //not sure
        m_ideas[i] = toCopy.m_ideas[i];
    std::cout << "Copy constructor called for Brain" << std::endl;
}

Brain& Brain::operator=(const Brain& toCopy)
{
    if (this != &toCopy)
        for(int i = 0; i < 100; i++)
            m_ideas[i] = toCopy.m_ideas[i];
    std::cout << "Copy assignment called for Brain" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "\33[1;31mDestructor called for Brain\33[0;m" << std::endl;
}

// std::string Brain::getIdea( int i) const { return (m_ideas[i]); }
// void Brain::setIdea(int i, std::string const idea) { m_ideas[i] = idea[i]; }