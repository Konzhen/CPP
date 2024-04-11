#include "Animal.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Animal::Animal() : _type("Creature")
{
	std::cout << "A new creature has emerged." << std::endl;
}

Animal::Animal(Animal const &animal)
{
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "The " << getType() << " has stoped living, it' s sad..." << std::endl;
}



//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Animal    &Animal::operator=(Animal const &animal)
{
	_type = animal.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::setType(std::string type)
{
	_type = type;
}

Brain	*Animal::getBrain()
{
	return (NULL);
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	Animal::makeSound() const
{
	std::cout << "The " << getType() << " is yelling a strange sound." << std::endl;
}