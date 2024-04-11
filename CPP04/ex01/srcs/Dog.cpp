/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:46:50 by angassin          #+#    #+#             */
/*   Updated: 2024/04/11 18:06:22 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain_;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain_ = new Brain(*other.brain_);
}

Dog& Dog::operator=(Dog const& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	return brain_->getIdea(index);
}

void Dog::setIdea(int index, std::string idea)
{
	brain_->setIdea(index, idea);
}

