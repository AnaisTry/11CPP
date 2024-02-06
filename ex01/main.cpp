/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:36:30 by angassin          #+#    #+#             */
/*   Updated: 2024/02/06 19:48:11 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cassert>

int main()
{
	    // Create a Contact object
    Contact contact("John", "Doe", "Johnny", "1234567890", "None");

    // Test the getter methods
    assert(contact.getFirstName() == "John");
    assert(contact.getLastName() == "Doe");
    assert(contact.getNickname() == "Johnny");
    assert(contact.getPhoneNumber() == "1234567890");
    assert(contact.getDarkestSecret() == "None");

    std::cout << "All tests passed." << std::endl;

    return 0;
}