#ifndef DOG_HPP
#define DOG_HPP

#include "aAnimal.hpp"
#include "Brain.hpp"

class Dog : public aAnimal
{
    public:
        Dog();
        Dog(const Dog&);
        Dog& operator=(const Dog&);
        ~Dog();

        void makeSound() const;
    private:
        Brain* m_brain;
};

#endif