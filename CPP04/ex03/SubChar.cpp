#include "SubChar.hpp"

void    delete_inventory(AMateria *m[4]);

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

SubChar::SubChar(std::string const name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << _name << " as rejoined the group!" << std::endl;
}

SubChar::SubChar(SubChar const &subchar)
{
    *this = subchar;
}

SubChar::~SubChar()
{
    delete_inventory(_inventory);
    std::cout << _name << " as left the group!" << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

SubChar    &SubChar::operator=(SubChar const &subchar)
{
    delete_inventory(_inventory);
    for (int i = 0; i < 4; i++)
    {
        if (subchar._inventory[i])
            _inventory[i] = subchar._inventory[i]->clone();
    }
    _name = subchar._name;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string const   &SubChar::getName() const
{
    return (_name);
}

AMateria *SubChar::getMateria(int idx) const
{
    return (_inventory[idx]);
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//


void                SubChar::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m->clone();
            std::cout << getName() << ": has equipped a " << m->getType() << " Materia." << std::endl;
            delete(m);
            std::cout << "Je suis un subchar" << std::endl;
            return ;
        }
    }
        std::cout << getName() << ": can't equip " << m->getType() << " Materia, inventory is full." << std::endl;
    
}

void                SubChar::unequip(int idx)
{
    if (_inventory[idx])
    {
        std::cout << getName() << ": has unequipped the " << _inventory[idx]->getType() << " Materia." << std::endl;
        _inventory[idx] = NULL;
        std::cout << "Je suis un subchar" << std::endl;
        return ;
    }
}

void                SubChar::use(int idx, ICharacter& target)
{
    if (_inventory[idx])
    {
        std::cout << getName() << ": ";
        _inventory[idx]->use(target);
        std::cout << "Je suis un subchar" << std::endl;
    }
}

void                SubChar::trololo()
{
    std::cout << "trololo" << std::endl;
}