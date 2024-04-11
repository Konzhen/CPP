#include "Cure.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const &cure) : AMateria(cure._type)
{
	*this = cure;
}

Cure::~Cure()
{

}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Cure    &Cure::operator=(Cure const &cure)
{
	_type = cure._type;
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void        Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

void		Cure::heal(SubChar *s)
{
	std::cout << "Heal is used on " << s->getName() << std::endl;
}