/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:33:55 by angassin          #+#    #+#             */
/*   Updated: 2024/02/21 21:17:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

// default constructor
Contact::Contact() : firstName_(""), lastName_(""), nickname_(""), 
	phoneNumber_(""), darkestSecret_("")
{
	// std::cout << "Contact default constructor called" << std::endl;
}

// parameterized constructor
Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) :
	firstName_(firstName), lastName_(lastName), nickname_(nickname), 
	phoneNumber_(phoneNumber), darkestSecret_(darkestSecret)
{
	// std::cout << "Parameterized constructor called" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact destroyed" << std::endl;
}

std::string Contact::getFirstName() const
{
	return firstName_;
}

std::string Contact::getLastName() const
{
	return lastName_;
}

std::string Contact::getNickname() const
{
	return nickname_;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber_;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret_;
}

// std::string Contact::formatString(std::string str)
// {
// 	if (str.length() > 10)
// 	{
// 		str.resize(9);
// 		str.append(".");
// 	}
// 	if (str.length() < 10)
// 	{
// 		str.insert(0, 10 - str.length(), ' ');
// 	}
// 	return str;
// }