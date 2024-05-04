/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:22:51 by angassin          #+#    #+#             */
/*   Updated: 2024/05/04 11:11:39 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is too low";
}

// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{
	std::cout << "Default bureaucrat created" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) 
{

	// handle exceptions
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	std::cout << "Bureaucrat " << name << " created with grade " << grade << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) 
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) 
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other) 
		_grade = other._grade;
		
	return *this;
}

// Getters
const std::string Bureaucrat::getName() const 
{
	return _name;
}

int Bureaucrat::getGrade() const 
{
	return _grade;
}

// Increment and decrement grade
void Bureaucrat::incrementGrade() 
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) 
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}