/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:38:24 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 15:09:40 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() 
{
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob"); me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob; 
	delete me; 
	delete src;
	return 0; 
}