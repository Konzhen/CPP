#include "Serializer.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

Serializer::Serializer()
{

}

Serializer::Serializer(Serializer const &serializer)
{
    *this = serializer;
}

Serializer::~Serializer()
{

}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

Serializer    &Serializer::operator=(Serializer const &serializer)
{
    (void)serializer;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

uintptr_t   Serializer::serialize(Data *ptr)
{
    return ((uintptr_t)ptr);
}

Data        *Serializer::deserialize(uintptr_t raw)
{
    void    *ptr = (void *)raw;

    return ((Data *)ptr);
}
