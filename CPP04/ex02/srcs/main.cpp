/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:20 by angassin          #+#    #+#             */
/*   Updated: 2024/04/12 18:14:17 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{

	/* Tests for the deep copy */
	Dog dog;
	Dog dog2;
	Cat cat;
	Cat cat2;
	std::cout << std::endl;
	
	// test assignment operator
	dog.setIdea(0, "Idea");
	dog2 = dog;
	cat.setIdea(0, "It smells of dog");
	cat2 = cat;

	dog.setIdea(0, "Another idea");
	cat.setIdea(0, "Cat's smell is better");

	// test copy constructor
	Dog dog3(dog);
	Cat cat3 = cat;
	std::cout << std::endl;

	std::cout << dog.getIdea(0) << std::endl;
	std::cout << dog2.getIdea(0) << std::endl;
	std::cout << dog3.getIdea(0) << std::endl;

	std::cout << cat.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl;
	std::cout << cat3.getIdea(0) << std::endl << std::endl;

	/* 
		In your main function, create and fill an array of Animal objects. Half of it will
		be Dog objects and the other half will be Cat objects. At the end of your program
		execution, loop over this array and delete every Animal. You must delete directly dogs
		and cats as Animals. The appropriate destructors must be called in the expected order.
	*/
	const int size = 4;
	AAnimal* AAnimals[size];

	std::cout << std::endl;
	
	// Creates an array of 4 animals
	for(int i = 0; i < size/2; i++)
		AAnimals[i] = new Dog();

	for(int i = size/2; i < size; i++)
		AAnimals[i] = new Cat();

	std::cout << std::endl;

	// Uses the animals
	for (int i = 0; i < size; i++)
	{
		std::cout << AAnimals[i]->getType() << " says: ";
		AAnimals[i]->makeSound();
	}

	std::cout << std::endl;
	
	// Deletes the animals
	for (int i = 0; i < size; i++)
		delete AAnimals[i];


	return 0;
}
