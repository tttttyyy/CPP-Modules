#ifndef CURE_HPP
#define CURE_HPP

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& );
        Cure& operator=(const Cure& );
        ~Cure();
        
        AMateria* clone() const; // or Cure* return type 
        void use(ICharacter& target);
};

#endif