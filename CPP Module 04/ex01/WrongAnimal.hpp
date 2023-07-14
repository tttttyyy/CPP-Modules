#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal&);
        WrongAnimal& operator=(const WrongAnimal&);
        ~WrongAnimal();
        void makeSound() const;
        std::string getType( void ) const ;
    protected:
        std::string m_type;
};

#endif