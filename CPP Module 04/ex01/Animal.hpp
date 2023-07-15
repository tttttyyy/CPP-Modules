#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal&);
        Animal& operator=(const Animal&);
        virtual ~Animal();
        
        virtual void makeSound() const;
        std::string getType( void ) const ;
    protected:
        std::string m_type;
};

#endif