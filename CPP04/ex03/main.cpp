#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "SubChar.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	
	Ice ice;
	Cure cure;
	
	std::cout << std::endl;	

	src->learnMateria(&ice);
	src->learnMateria(&cure);
	src->learnMateria(&cure);
	src->learnMateria(&cure);
	src->learnMateria(&cure);
	
	std::cout << std::endl;	
	
	ICharacter* cloud = new Character("Cloud");
	AMateria* tmp;

	std::cout << std::endl;

	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	delete(tmp);
	tmp = cloud->getMateria(3);
	cloud->unequip(3);
	cloud->equip(NULL);
	delete(tmp);

	std::cout << std::endl;

	ICharacter* tifa = new Character("Tifa");
	cloud->use(0, *tifa);
	cloud->use(1, *tifa);

	std::cout << std::endl;

	SubChar *barett = new SubChar("Barett");
	ICharacter *vincent = new SubChar("Vincent");
	Yufi *yufi	= new Yufi("Yufi");

	cloud->use(0, *(ICharacter *)barett);
	Cure	cure;

	cure.heal((SubChar *)vincent);


	std::cout << std::endl;

	delete tifa;
	delete cloud;
	delete barett;
	delete src;

	return 0;
}