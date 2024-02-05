/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:33:55 by angassin          #+#    #+#             */
/*   Updated: 2024/02/05 15:08:08 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) :
	firstName_(firstName), lastName_(lastName), nickname_(nickname), 
	phoneNumber_(phoneNumber)
{
	std::cout << "Constructor called" << std::endl;
	std::string Contact::getFirstName() const{
		return firstName_;
	}

}

Contact::~Contact()
{
	std::cout << "Contact destroyed" << std::endl;
}
