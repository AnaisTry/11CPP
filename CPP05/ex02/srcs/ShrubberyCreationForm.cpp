/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:16:35 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

#include <fstream>


// Default constructor
ShrubberyCreationForm:: ShrubberyCreationForm() : AForm("shrubberyBlankForm", 145, 137){}

// Parameterized constructor
ShrubberyCreationForm:: ShrubberyCreationForm(const std::string &target) : 
	AForm("shrubberyCreationForm", 145, 137), _target(target){}

// Destructor
 ShrubberyCreationForm::~ ShrubberyCreationForm(){}

// Copy constructor
 ShrubberyCreationForm:: ShrubberyCreationForm(const  ShrubberyCreationForm &other) : AForm(other)
 {
	_target = other._target;
 }

// Assignment operator
 ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const  ShrubberyCreationForm &other) 
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) 
	{
		AForm::operator=(other);
		_target = other._target;
	}
		
	return *this;
}

// Execute form
void  ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	file << "      _-_\n";
    file << "   /~~   ~~\\\n";
    file << " /~~        ~~\\\n";
    file << "{              }\n";
    file << " \\ _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "_ -    | |   -_\n";
    file << "  \\__/\\\\ //\\__/\n";
		
	file.close();
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const  ShrubberyCreationForm &form) 
{
	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
		<< ", grade to execute " << form.getExecGrade() 
		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
	return out;
}
