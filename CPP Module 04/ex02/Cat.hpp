#ifndef CAT_HPP
#define CAT_HPP

#include "aAnimal.hpp"
#include "Brain.hpp"

class Cat : public aAnimal
{
    public:
        Cat();
        Cat(const Cat&);
        Cat& operator=(const Cat&);
        ~Cat();

        void makeSound() const;
    private:
        Brain* m_brain;
};

#endif