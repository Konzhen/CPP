#include "Dog.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Dog::Dog()
{
	setType("Dog");
	_brain = new Brain();
	std::cout << "A newcomer as arrived, the best human' s friend, and a golden one." << std::endl;
}

Dog::Dog(Dog const &dog) : Animal()
{
	*this = dog;
}

Dog::~Dog()
{
	delete(_brain);
	std::cout << "Oh no, our best friend left us, see you next time little puppy." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Dog    &Dog::operator=(Dog const &dog)
{
	_brain = dog._brain;
	_type = dog.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

Brain	*Dog::getBrain()
{
	return (_brain);
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	Dog::makeSound() const
{
	std::cout << "Woof Woof !" << std::endl;
}
