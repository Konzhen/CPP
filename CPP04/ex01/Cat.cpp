#include "Cat.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Cat::Cat()
{
	setType("Cat");
	_brain = new Brain();
	std::cout << "Oh no... Honey ? Who let this devil come in our house ?!" << std::endl;
}

Cat::Cat(Cat const &cat)
{
	*this = cat;
}

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Finally, this little brat left us." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Cat    &Cat::operator=(Cat const &cat)
{
	_brain = cat._brain;
	_type = cat.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

Brain	*Cat::getBrain()
{
	return (_brain);
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	Cat::makeSound() const
{
	std::cout << "Meow Meow !" << std::endl;
}
