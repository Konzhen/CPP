#include "Brain.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Brain::Brain()
{
	std::cout << "Is a new Brain, it' s a new day." << std::endl;
	std::srand(std::time(0));

	const char	s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

	for (int size = 0; size < 100; size++)
    	for (int i = 0; i < 20; ++i)
		{
        	int index = std::rand() % (sizeof(s) - 1);
        	_ideas[size] += s[index];
    	}
}

Brain::Brain(Brain const &brain)
{
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "Tears have filled my bone, my brain as just gone." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Brain    &Brain::operator=(Brain const &brain)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

void	Brain::getRandomIdea() const
{
	int	i = std::rand() % 100;

	std::cout << "Idea number " << i << ":" << _ideas[i] << std::endl;
}
