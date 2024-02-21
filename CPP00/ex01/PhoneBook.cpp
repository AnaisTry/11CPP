/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/21 21:12:15 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <limits>
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
void PhoneBook::addContact_(const Contact &contact)
{
	contacts_[oldestContactIndex_] = contact;
    oldestContactIndex_ = (oldestContactIndex_ + 1) % PhoneBook::MAX_CONTACTS;

    if (contactsNumber_ < PhoneBook::MAX_CONTACTS)
        contactsNumber_++;
	
}

bool PhoneBook::getInput(std::string &input, const std::string &prompt) const
{
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cerr << "EOF detected\n";
		return false;
	}
	if (std::cin.fail())
	{
		std::cerr << "Error reading input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
	}
	return true;
}

/*
	Takes input from the user to create a new Contact object and adds it to the contacts_ array.
*/
void PhoneBook::addContactPrompt()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (!getInput(firstName, "Enter the first name: ")) return;
	if (!getInput(lastName, "Enter the last name: ")) return;
	if (!getInput(nickname, "Enter the nickname: ")) return;
	if (!getInput(phoneNumber, "Enter the phone number: ")) return;
	if (!getInput(darkestSecret, "Enter the darkest secret: ")) return;

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->addContact_(newContact);
	std::cout << "Contact added" << std::endl;
	std::cout << std::endl;
}

std::string PhoneBook::truncate_(const std::string &str) const
{
	return str.length() > 10 ? str.substr(0, 9) + "." : str;
}
void PhoneBook::printSearchTable_() const
{
	// std::cout <<
	// Contact::formatString("Index") << "| " <<
	// Contact::formatString("First Name") << "| " <<
	// Contact::formatString("Last Name") << "| " <<
	// Contact::formatString("Nickname") << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << "| "
          << std::setw(10) << "First Name" << "| "
          << std::setw(10) << "Last Name" << "| "
          << std::setw(10) << "Nickname" << std::endl;
		  
	for (int i = 0; i < PhoneBook::contactsNumber_; i++)
	{
		Contact contact = getContact_(i);

		// std::cout << std::setw(10) << std::setfill(' ') << i << "| " <<
		// Contact::formatString(contact.getFirstName()) << "| " <<
		// Contact::formatString(contact.getLastName()) << "| " <<
		// Contact::formatString(contact.getNickname()) << std::endl;

		std::cout << std::setw(10) << std::setfill(' ') << i << "| " <<
		std::setw(10) << std::setfill(' ') << truncate_(contact.getFirstName()) << "| " <<
		std::setw(10) << std::setfill(' ') << truncate_(contact.getLastName()) << "| " <<
		std::setw(10) << std::setfill(' ') << truncate_(contact.getNickname()) << std::endl;
	}
	std::cout << std::endl;
}

/*
	Returns the Contact object at the given index.
*/
Contact PhoneBook::getContact_(int index) const
{
	if (index < 0 || index >= PhoneBook::MAX_CONTACTS || index >= contactsNumber_)
		throw std::out_of_range("Invalid index");
	
	return contacts_[index];
}

void PhoneBook::searchContactPrompt() const
{
	printSearchTable_();
	
	std::string chosenIndex;
	if (!getInput(chosenIndex, "Enter the index of the contact you want to display: "))
		return;

	std::stringstream converted(chosenIndex); //similar to std::stoi
	int i = -1;
	converted >> i;
	if (converted.fail())
	{
		std::cerr << "Invalid input\n"<< std::endl;
		return;
	}
	if (i >= 0 && i < PhoneBook::MAX_CONTACTS)
	{
		try
		{
			Contact contact = getContact_(i);
			std::cout << "First name: " << contact.getFirstName() << std::endl;
			std::cout << "Last name: " << contact.getLastName() << std::endl;
			std::cout << "Nickname: " << contact.getNickname() << std::endl;
			std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Invalid index" << std::endl;
	std::cout << std::endl;
}
