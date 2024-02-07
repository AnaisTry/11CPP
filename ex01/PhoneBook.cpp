/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/07 14:32:32 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contactsNumber_(0), oldestContact_(0)
{
	for(int i = 0; i < 8; i++)
	{
		contacts_[i] = Contact::createContact();
	}
	std::cout << "Phonebook created" << std::endl;
} 

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}