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
    uintptr_t tmp = reinterpret_cast<uintptr_t>(ptr);

    return (tmp);
}

Data        *Serializer::deserialize(uintptr_t raw)
{
    Data *tmp = reinterpret_cast<Data *>(raw);

    return (tmp);
}
