/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:36:30 by angassin          #+#    #+#             */
/*   Updated: 2024/02/09 18:49:53 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cassert>

int main()
{
	// Create a PhoneBook object
    PhoneBook phoneBook;
	std::string command;
	
	do
	{
		if (!phoneBook.getInput(command, "Enter a command (ADD, SEARCH, EXIT): "))
			break;

		if (command == "ADD")
			phoneBook.addContactPrompt();
		else if (command == "SEARCH")
			phoneBook.searchContactPrompt();
	} 
	while (command != "EXIT");

	/* Dev tests*/
//     // Create some Contact objects
//    Contact contact1("John", "Doe", "Johnny", "1234567890", "None");
//    Contact contact2("Jane", "Doe", "Jenny", "0987654321", "None");

	

    // // Add the contacts to the phoneBook
    //SE phoneBook.addContact(contact1);
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

    return 0;
}