#include "MateriaSource.hpp"

void    delete_inventory(AMateria *m[4]);

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _memory[i] = NULL;
    std::cout << "You found a Materia source." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &materiasource)
{
    *this = materiasource;
}

MateriaSource::~MateriaSource()
{
    delete_inventory(_memory);
    std::cout << "Materia source has been destroyed." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

MateriaSource    &MateriaSource::operator=(MateriaSource const &materiasource)
{
    delete_inventory(_memory);
    for (int i = 0; i < 4; i++)
    {
        if (materiasource._memory[i])
            _memory[i] = materiasource._memory[i]->clone();
    }
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void        MateriaSource::learnMateria(AMateria *amateria)
{
    if (!amateria)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_memory[i])
        {
            _memory[i] = amateria->clone();
            std::cout << "Materia source has learned " << amateria->getType() << " Materia." << std::endl;
            return ;
        }
    }
        std::cout << "Can't learn " << amateria->getType() << " Materia, Materia's source memory is full." << std::endl;
}

AMateria    *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_memory[i] && !_memory[i]->getType().compare(type))
        {
            std::cout << type << " Materia succesfully created." << std::endl;
            return (_memory[i]->clone());
        }
    }
    std::cout << "Materia source didn't learn " << type << " Materia yet." << std::endl;
    return (NULL);
}
