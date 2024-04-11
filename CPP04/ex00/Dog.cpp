#include "Dog.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Dog::Dog()
{
	setType("Dog");
	std::cout << "A newcomer as arrived, the best human' s friend, and a golden one." << std::endl;
}

Dog::Dog(Dog const &dog)
{
	_type = dog.getType();
}

Dog::~Dog()
{
	std::cout << "Oh no, our best friend left us, see you next time little puppy." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Dog    &Dog::operator=(Dog const &dog)
{
	_type = dog.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	Dog::makeSound() const
{
	std::cout << "Woof Woof !" << std::endl;
}
