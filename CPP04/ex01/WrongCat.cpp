#include "WrongCat.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << "Oh no... Honey ? Who let this devil come in our house ?!" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongCat)
{
	_type = wrongCat.getType();
}

WrongCat::~WrongCat()
{
	std::cout << "Finally, this little brat left us." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

WrongCat    &WrongCat::operator=(WrongCat const &wrongCat)
{
	_type = wrongCat.getType();
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	WrongCat::makeSound() const
{
	std::cout << "Miihooaaar Miihooaaar, Cough! Cough! Damn, i hate this job..." << std::endl;
}
