#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain&);
        Brain& operator=(const Brain&);
        ~Brain();

        // std::string getIdea(int) const;
        // void        setIdea(int, std::string const);
    private:
        std::string m_ideas[100];
};

#endif