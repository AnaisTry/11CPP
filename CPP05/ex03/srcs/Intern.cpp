/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:07:11 by angassin          #+#    #+#             */
/*   Updated: 2024/05/10 13:32:53 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern() 
{
	std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// Assignment operator
Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}


AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::_formTypes[] = 
{
	{"shrubbery creation", &Intern::createShrubberyCreationForm},
	{"robotomy request", &Intern::createRobotomyRequestForm},
	{"presidential pardon", &Intern::createPresidentialPardonForm}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int i = 0; i < 3; ++i)
	{
		if (formName == _formTypes[i].name)
		{
			std::cout << "Intern creates ";
			return (this->*_formTypes[i].creator)(target);
		}
	}
	std::cerr << "Error: form name not found" << std::endl;
	return NULL;
}
