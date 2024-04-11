#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
const Animal	*creature = new Animal;
const Animal    *cat = new Cat;
const Animal	*puppy = new Dog;

std::cout << std::endl;

creature->makeSound();
puppy->makeSound();
cat->makeSound();

std::cout << std::endl;

delete(creature);
delete(puppy);
delete(cat);

std::cout << std::endl << std::endl;

const WrongAnimal	*wrongCreature = new WrongAnimal;
const WrongAnimal	*brat = new WrongCat;
const WrongCat		catty;

wrongCreature->makeSound();
brat->makeSound();
catty.makeSound();

std::cout << std::endl;

delete(wrongCreature);
delete(brat);

std::cout << std::endl;

}