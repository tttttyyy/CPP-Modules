#ifndef ICE_HPP
#define ICE_HPP

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& );
        Ice& operator=(const Ice& );
        ~Ice();
        
        AMateria* clone() const; // or ice* return type 
        void use(ICharacter& target);
};

#endif