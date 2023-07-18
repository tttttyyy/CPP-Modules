#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & toCopy )
{
    for (int i = 0; i < 4; i++)
        if (toCopy.array[i])
            array[i] = toCopy.array[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource & toCopy )
{
    if (this != &toCopy)
    {
        for(int i = 0; i < 4; ++i)
        {
            if (!array[i])
            {
                delete array[i];
                array[i] = NULL;
            }
        }
        for(int i = 0; i < 4; ++i)
            if (toCopy.array[i])
                array[i] = toCopy.array[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; ++i)
    {
        delete array[i];
        array[i] = NULL;
    }
}


void MateriaSource::learnMateria(AMateria* toLearn)
{
    for(int i = 0; i < 4; ++i)
    {
        if (!array[i])
        {
            array[i] = toLearn;
            return;
        }
    }
    std::cout << "[ERROR] No space to learn !" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4 && array[i]; ++i)
        if (array[i]->getType() == type)
            return (array[i]->clone());
    std::cout << "[ERROR] No such Materia !" << std::endl;
    return (0);
}