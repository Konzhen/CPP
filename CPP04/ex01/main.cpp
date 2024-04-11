#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{

    Animal *zoo[10];

    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
        zoo[i] = new Dog();

    std::cout << std::endl;

    for (int i = 5; i < 10; i++)
        zoo[i] = new Cat();

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << zoo[i]->getType() << std::endl;
        zoo[i]->getBrain()->getRandomIdea();
        zoo[i]->getBrain()->getRandomIdea();
        zoo[i]->getBrain()->getRandomIdea();
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        delete(zoo[i]);

    std::cout << std::endl;
}