/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:17:46 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 12:20:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character() : name_("default")
{
	for (int i = 0; i < 4; i++)
		inventory_[i] = nullptr;
}

Character::Character(std::string name) : name_(name)
{
	for (int i = 0; i < 4; i++)
		inventory_[i] = nullptr;
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory_[i])
			delete inventory_[i];
	}
}

// Copy constructor
Character::Character(const Character& other) : name_(other.name_)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory_[i])
			inventory_[i] = other.inventory_[i]->clone();
		else
			inventory_[i] = nullptr;
	}
}

// Assignment operator
Character& Character::operator=(Character const& other)
{
	if (this != &other)
	{
		this->name_ = other.name_;
		for (int i = 0; i < 4; i++)
		{
			if (inventory_[i])
				delete inventory_[i];
			if (other.inventory_[i])
				inventory_[i] = other.inventory_[i]->clone();
			else
				inventory_[i] = nullptr;
		}
	}
	return *this;
}

// Getter
const std::string& Character::getName() const
{
	return this->name_;
}

// Member functions
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory_[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory_[idx])
		inventory_[idx]->use(target);
}
