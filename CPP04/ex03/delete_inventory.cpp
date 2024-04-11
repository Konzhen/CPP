#include "AMateria.hpp"

void	delete_inventory(AMateria *m[4])
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (m[i])
			delete(m[i]);
	}
}