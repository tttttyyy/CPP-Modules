#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        array[i] = NULL;
    for (int i = 0; i < 4; i++)
        floor[i] = NULL;
}

Character::Character( std::string const & name) : m_name(name)
{
    for (int i = 0; i < 4; i++)
        array[i] = NULL;
    for (int i = 0; i < 4; i++)
        floor[i] = NULL;
}

Character::Character( const Character& toCopy ) : m_name(toCopy.m_name)
{
	// std::cout << "Called Character's copy constructor\n";
    for (int i = 0; i < 4; i++)
    {
        if (toCopy.array[i])
            array[i] = toCopy.array[i]->clone();
        if (toCopy.floor[i])
            floor[i] = toCopy.floor[i]->clone();
    }
}

Character&  Character::operator=( const Character& toCopy )
{
	// std::cout << "Called Character's copy assigment constructor\n";
    if (this != &toCopy)
    {
		for(int i = 0; i < 4; ++i)
    	{
			if (array[i])
			{
    	    	delete array[i];
    	    	array[i] = NULL;
			}
    	}
		for(int i = 0; i < 4; ++i)
    	{
			if (floor[i])
			{
    	    	delete floor[i];
    	    	floor[i] = NULL;
			}
    	}
        m_name = toCopy.m_name;
        for (int i = 0; i < 4; i++)
        {
            if (toCopy.array[i])
                array[i] = toCopy.array[i]->clone();
            if (toCopy.floor[i])
                floor[i] = toCopy.floor[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; ++i)
    {
		if (array[i])
		{
        	delete array[i];
        	array[i] = NULL;
		}
    }
	for(int i = 0; i < 4; ++i)
    {
		if (floor[i])
		{
        	delete floor[i];
        	floor[i] = NULL;
		}
    }
}

std::string const & Character::getName() const { return (m_name); } 

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!array[i])
        {
            array[i] = m;
            return ;
        }
    }
    std::cout << "[ERROR] Array of Materias is already full !" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
    {
        if (!array[idx])
        {
            std::cout << "[ERROR] No Materia in such index !" << std::endl;
			return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (!floor[i])
            {
                floor[i] = array[idx];
                array[idx] = NULL;
                return;
            }
        }
    }
    std::cout << "[ERROR] Incorrect index !" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && array[idx])
        array[idx]->use(target);
}