/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:20 by angassin          #+#    #+#             */
/*   Updated: 2024/04/10 12:31:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	// const Animal* dog = new Dog();
	// const Animal* cat = new Cat();
	const int size = 4;
	Animal* animals[size];

	std::cout << std::endl;
	
	// Creates an array of 4 animals
	for(int i = 0; i < size/2; i++)
		animals[i] = new Dog();

	for(int i = size/2; i < size; i++)
		animals[i] = new Cat();

	std::cout << std::endl;

	// Uses the animals
	for (int i = 0; i < size; i++)
	{
		animals[i]->getType();
		animals[i]->makeSound();
	}

	std::cout << std::endl << std::endl;
	
	// Deletes the animals
	for (int i = 0; i < size; i++)
		delete animals[i];

	


	// std::cout << std::endl << dog->getType() << " " << std::endl;
	// std::cout << cat->getType() << " " << std::endl;

	// std::cout << std::endl;
	
	// delete dog;
	// delete cat;


	return 0;
}
