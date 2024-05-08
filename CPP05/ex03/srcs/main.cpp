/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/08 16:30:38 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


#include <sstream> 

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	
	std::cout << GREEN << "Test makeForm():" << RESET << std::endl << std::endl;
	Intern i;

	AForm* badForm = i.makeForm("bad form", "Void");
	AForm* emptyTargetForm = i.makeForm("shrubbery creation", "");
	AForm* s = i.makeForm("shrubbery creation", "Garden");
	AForm* r1 = i.makeForm("robotomy request", "Narval");
	AForm* p = i.makeForm("presidential pardon", "Innocent");
	std::cout << std::endl;

	std::cout << GREEN << "Test execution:" << RESET << std::endl << std::endl;	
	Bureaucrat b1("Leslie", 5);
	std::cout << std::endl;

	if (badForm != NULL)
	{
		b1.signForm(*badForm);
		b1.executeForm(*badForm);
	}

	b1.signForm(*s);
	b1.signForm(*r1);
	b1.signForm(*p);
	std::cout << std::endl;
	
	b1.executeForm(*s);	
	b1.executeForm(*r1);
	b1.executeForm(*p);
	std::cout << std::endl;
	
	delete badForm;
	delete emptyTargetForm;
	delete s;
	delete r1;
	delete p;

	return 0;
}