/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/08 07:47:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "PhoneBook.hpp"
#include "Contact.hpp"

// Default constructor with initialization list
PhoneBook::PhoneBook(): contactsNumber_(0), oldestContactIndex_(0)
{
	std::cout << "Phonebook created" << std::endl;
} 

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

/*
	Takes a reference to a Contact object and adds it to the contacts_ array.
	The use of the reference is to avoid copying the Contact object.
	It's const to avoid modifying the Contact object.
	When the contacts_ array is full, the oldest contact is replaced by the new one.
*/ 
void PhoneBook::addContact(const Contact &contact)
{
	contacts_[oldestContactIndex_] = contact;
    oldestContactIndex_ = (oldestContactIndex_ + 1) % PhoneBook::MAX_CONTACTS;

    if (contactsNumber_ < PhoneBook::MAX_CONTACTS)
        contactsNumber_++;
	
}

/*
	Returns the Contact object at the given index.
*/
Contact PhoneBook::getContact(int index) const
{
	if (index < 0 || index >= PhoneBook::MAX_CONTACTS)
		throw std::out_of_range("Invalid index");
	
	return contacts_[index];
}
