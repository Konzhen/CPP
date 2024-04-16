#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mut;

	mut.push(1);
	mut.push(12);
	mut.push(24);

	for (MutantStack<int>::it it = mut.begin(); it != mut.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}