/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:31:52 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 13:57:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


// Default constructor
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = NULL;
	}
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory_[i] != NULL)
		{
			delete inventory_[i];
		}
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

// Assignment operator
MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory_[i] != NULL)
			{
				delete inventory_[i];
			}
			if (other.inventory_[i] != NULL)
			{
				inventory_[i] = other.inventory_[i]->clone();
			}
			else
			{
				inventory_[i] = NULL;
			}
		}
	}
	return *this;
}

//Member functions
void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = materia->clone();
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory_[i] != NULL && inventory_[i]->getType() == type)
		{
			return inventory_[i]->clone();
		}
	}
	return NULL;
}
