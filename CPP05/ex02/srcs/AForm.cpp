/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:00:42 by angassin          #+#    #+#             */
/*   Updated: 2024/05/05 15:23:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() 
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return "Grade is too low";
}

// Default constructor
AForm::AForm() : _name("blankForm"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default form created" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string &name, const int signGrade, const int execGrade) : 
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if ( signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	
	std::cout << "Form " << name << " created with minimum grade to sign " << signGrade 
		<< " and minimum grade to execute " << execGrade << std::endl;
}

// Destructor
AForm::~AForm() 
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), 
	_signGrade(other._signGrade), _execGrade(other._execGrade) 
{
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
AForm& AForm::operator=(const AForm &other) 
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) 
	{
		_signed = other._signed;
	}
		
	return *this;
}

// Getters
const std::string AForm::getName() const 
{
	return _name;
}

int AForm::getSignGrade() const 
{
	return _signGrade;
}

int AForm::getExecGrade() const 
{
	return _execGrade;
}

bool AForm::isSigned() const 
{
	return _signed;
}

// Sign form
void AForm::beSigned(const Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	
	_signed = true;
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const AForm &form) 
{
	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
		<< ", grade to execute " << form.getExecGrade() 
		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
	return out;
}
