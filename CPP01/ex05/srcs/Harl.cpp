/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:23:36 by angassin          #+#    #+#             */
/*   Updated: 2024/03/17 22:52:59 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl()
{
	std::cout << "Harl constructed with default constructor" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-ketchup burger. "
	"I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
	"You didn’t put enough bacon in my burger! "
	"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I’ve been coming here for years and you just started "
	"working here last month. "
	"I cannot believe you are already raising prices!" << std::endl;
}

void Harl::error()
{
	std::cout << "I can’t eat this. I’m allergic to pickles. "
	"Also, I asked for no pickles." << std::endl;
}

Harl::Complaint Harl::complaints[4] = {
	{"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error}
};

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (complaints[i].level == level)
		{
			(this->*complaints[i].complaint)();
			return ;
		}
	}
	std::cout << "Unknown complaint level" << std::endl;
}
