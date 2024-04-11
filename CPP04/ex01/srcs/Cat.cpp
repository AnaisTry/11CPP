/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:42:14 by angassin          #+#    #+#             */
/*   Updated: 2024/04/11 18:06:39 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain_=new Brain(*other.brain_);
}

Cat& Cat::operator=(Cat const& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	return brain_->getIdea(index);
}

void Cat::setIdea(int index, std::string idea)
{
	brain_->setIdea(index, idea);
}
