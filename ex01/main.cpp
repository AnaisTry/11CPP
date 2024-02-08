/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:36:30 by angassin          #+#    #+#             */
/*   Updated: 2024/02/08 09:09:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cassert>

int main()
{
//     // Create some Contact objects
//    Contact contact1("John", "Doe", "Johnny", "1234567890", "None");
//    Contact contact2("Jane", "Doe", "Jenny", "0987654321", "None");

	// Create a PhoneBook object
    PhoneBook phoneBook;

    // // Add the contacts to the phoneBook
    // phoneBook.addContact(contact1);
    // phoneBook.addContact(contact2);

	// try {
	// 	// Get the contacts from the phoneBook
	// 	Contact retrievedContact1 = phoneBook.getContact(0);
	// 	Contact retrievedContact2 = phoneBook.getContact(1);

	// 	// Check if the retrieved contacts are the same as the ones we added
	// 	assert(retrievedContact1.getFirstName() == "John");
	// 	assert(retrievedContact1.getPhoneNumber() == "1234567890");
	// 	assert(retrievedContact2.getFirstName() == "Jane");
	// 	assert(retrievedContact2.getPhoneNumber() == "0987654321");

	// 	std::cout << "All tests passed." << std::endl;
	// 	} catch (const std::out_of_range& e) {
	// 		std::cerr << "Caught an out-of-range exception: " << e.what() << std::endl;}

	std::string command;
	while (true)
	{
		std::cout << "Enter a command: ";
		if (std::getline(std::cin, command).fail())
			break;	

		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			std::cout << "Enter the first name: ";
			// if (std::getline(std::cin, firstName).fail())
			// 	break;
			if (!std::getline(std::cin, firstName)) 
			{
				if (std::cin.eof()) {
					break; // Exit the loop if EOF is encountered
				}
				std::cerr << "Error reading first name\n";
				std::cin.clear(); // Clear the error state
				continue; // Skip the rest of the loop and start the next iteration
			}
			std::cout << "Enter the last name: ";
			if (std::getline(std::cin, lastName).fail())
				break;
			std::cout << "Enter the nickname: ";
			if (std::getline(std::cin, nickname).fail())
				break;
			std::cout << "Enter the phone number: ";
			if (std::getline(std::cin, phoneNumber).fail())
				break;
			std::cout << "Enter the darkest secret: ";
			if (std::getline(std::cin, darkestSecret).fail())
				break;

			Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
			for (int i = 0; i < PhoneBook::MAX_CONTACTS; i++)
			{
				Contact contact = phoneBook.getContact(i);
				std::cout << "         " << i << "|" << contact.getFirstName() << "|" << contact.getLastName() << "|" << contact.getNickname() << std::endl;
			}
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
    return 0;
}