#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
    //Animal  animal;
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    std::cout << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;
}