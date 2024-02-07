/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/07 16:17:22 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(): contactsNumber_(0), oldestContact_(0)
{
	std::cout << "Phonebook created" << std::endl;
} 

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

void PhoneBook::addContact(Contact contact)
{
	if (contactsNumber_ < 8)
	{
		contact[]
	}
	
}