/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:33 by angassin          #+#    #+#             */
/*   Updated: 2024/02/03 22:59:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Phonebook created" << std::endl;
} 

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}