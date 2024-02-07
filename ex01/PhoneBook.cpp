/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/07 16:45:08 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(): contactsNumber_(0), oldestContactIndex_(0)
{
	std::cout << "Phonebook created" << std::endl;
} 

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

void PhoneBook::addContact(const Contact &contact)
{
	if (contactsNumber_ < 8)
	{
		contacts_[contactsNumber_] = contact;
		contactsNumber_++;
	}
	else
	{
		contacts_[oldestContactIndex_] = contact;
		oldestContactIndex_ = (oldestContactIndex_ + 1) % 8;
	}
	
}