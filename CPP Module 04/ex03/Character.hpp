#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character( std::string const & );
        Character( const Character& );
        Character&  operator=( const Character& );
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string m_name;
        AMateria *array[4];
        AMateria *floor[4];

};

#endif