# include "ICharacter.hpp"
#include "AMateria.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << _type << " Materia has been created." << std::endl;
}

AMateria::AMateria(AMateria const &amateria)
{
	*this = amateria;
}

AMateria::~AMateria()
{
	//std::cout << _type << " Materia has been destroyed." << std::endl;
}

//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

AMateria    &AMateria::operator=(AMateria const &amateria)
{
	_type = amateria._type;
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string const	&AMateria::getType() const
{
	return (_type);
}

void				AMateria::setType(std::string type)
{
	_type = type;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void				AMateria::use(ICharacter &target)
{
	std::cout << "* " << _type << " has been used on " << target.getName() << std::endl;
}
