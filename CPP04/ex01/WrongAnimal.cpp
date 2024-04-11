#include "WrongAnimal.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

WrongAnimal::WrongAnimal() : _type("Creature")
{
	std::cout << "A new creature has emerged." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal)
{
	_type = wrongAnimal.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The " << getType() << " has stoped living, it' s sad..." << std::endl;
}



//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

WrongAnimal    &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	_type = wrongAnimal.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	WrongAnimal::makeSound() const
{
	std::cout << "The " << getType() << " is yelling a strange sound." << std::endl;
}