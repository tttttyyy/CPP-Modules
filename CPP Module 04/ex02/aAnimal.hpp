#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class aAnimal
{
    public:
        aAnimal();
        aAnimal(const aAnimal&);
        aAnimal& operator=(const aAnimal&);
        virtual ~aAnimal();
        
        virtual void makeSound() const = 0;
        std::string getType( void ) const ;
    protected:
        std::string m_type;
};

#endif