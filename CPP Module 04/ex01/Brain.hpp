#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
    public:
        Brain();
        Brain(const Brain&);
        Brain& operator=(const Brain&);
        ~Brain();
    private:
        std::string m_ideas[100];
}

#endif