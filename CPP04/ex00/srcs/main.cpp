/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:20 by angassin          #+#    #+#             */
/*   Updated: 2024/04/09 16:44:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	
	delete dog;
	delete cat;
	delete meta;


	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* cat2 = new WrongCat();
	const WrongCat* cat3 = new WrongCat();

	std::cout << std::endl << cat2->getType() << " " << std::endl;
	cat2->makeSound(); //will output the WrongAnimal sound!
	std::cout << cat3->getType() << " " << std::endl;
	cat3->makeSound(); //will output the WrongCat sound!

	std::cout << std::endl;

	delete cat3;
	delete cat2;
	delete meta2;

	return 0;
}
