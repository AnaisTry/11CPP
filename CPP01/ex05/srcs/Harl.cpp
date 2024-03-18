/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:23:36 by angassin          #+#    #+#             */
/*   Updated: 2024/03/18 12:45:53 by angassin         ###   ########.fr       */
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
	std::cout << "I think I deserve to have some extra bacon for free. " 
	"I’ve been coming for years whereas you started working here since last month."<< std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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
