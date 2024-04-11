#include "Character.hpp"

void    delete_inventory(AMateria *m[4]);

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Character::Character(std::string const name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << _name << " as rejoined the group!" << std::endl;
}

Character::Character(Character const &character)
{
    *this = character;
}

Character::~Character()
{
    delete_inventory(_inventory);
    std::cout << _name << " as left the group!" << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Character    &Character::operator=(Character const &character)
{
    delete_inventory(_inventory);
    for (int i = 0; i < 4; i++)
    {
        if (character._inventory[i])
            _inventory[i] = character._inventory[i]->clone();
    }
    _name = character._name;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string const   &Character::getName() const
{
    return (_name);
}

AMateria *Character::getMateria(int idx) const
{
    return (_inventory[idx]);
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//


void                Character::equip(AMateria* m)
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
            return ;
        }
    }
        std::cout << getName() << ": can't equip " << m->getType() << " Materia, inventory is full." << std::endl;
    
}

void                Character::unequip(int idx)
{
    if (_inventory[idx])
    {
        std::cout << getName() << ": has unequipped the " << _inventory[idx]->getType() << " Materia." << std::endl;
        _inventory[idx] = NULL;
        return ;
    }
}

void                Character::use(int idx, ICharacter& target)
{
    if (_inventory[idx])
    {
        std::cout << getName() << ": ";
        _inventory[idx]->use(target);
    }
}

