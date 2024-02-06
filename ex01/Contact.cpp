/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:33:55 by angassin          #+#    #+#             */
/*   Updated: 2024/02/06 19:50:02 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) :
	firstName_(firstName), lastName_(lastName), nickname_(nickname), 
	phoneNumber_(phoneNumber), darkestSecret_(darkestSecret)
{
	std::cout << "Constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destroyed" << std::endl;
}

std::string Contact::getFirstName() const{
		return firstName_;
	}

std::string Contact::getLastName() const{
		return lastName_;
	}

std::string Contact::getNickname() const{
		return nickname_;
	}

std::string Contact::getPhoneNumber() const{
		return phoneNumber_;
	}

std::string Contact::getDarkestSecret() const{
		return darkestSecret_;
	}
