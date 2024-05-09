/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:00:42 by angassin          #+#    #+#             */
/*   Updated: 2024/05/04 19:53:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


// Exceptions
const char* Form::GradeTooHighException::what() const throw() 
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return "Grade is too low";
}

// Default constructor
Form::Form() : _name("blankForm"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default form created" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string &name, const int signGrade, const int execGrade) : 
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
Form::~Form() 
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _signed(other._signed), 
	_signGrade(other._signGrade), _execGrade(other._execGrade) 
{
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Form& Form::operator=(const Form &other) 
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) 
	{
		_signed = other._signed;
	}
		
	return *this;
}

// Getters
const std::string Form::getName() const 
{
	return _name;
}

int Form::getSignGrade() const 
{
	return _signGrade;
}

int Form::getExecGrade() const 
{
	return _execGrade;
}

bool Form::isSigned() const 
{
	return _signed;
}

// Sign form
void Form::beSigned(const Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	
	_signed = true;
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const Form &form) 
{
	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
		<< ", grade to execute " << form.getExecGrade() 
		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
	return out;
}
