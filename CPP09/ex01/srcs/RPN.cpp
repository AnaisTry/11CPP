/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:33 by angassin          #+#    #+#             */
/*   Updated: 2024/11/04 17:08:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Default constructor
RPN::RPN()
{
	// std::cout << "RPN created" << std::endl;
}

// Destructor
RPN::~RPN()
{
	// std::cout << "RPN destroyed" << std::endl;
}

// Copy constructor
RPN::RPN(const RPN& other)
{
	// std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
RPN& RPN::operator=(RPN const& other)
{
	// std::cout << "RPN assignment operator called" << std::endl;
	if (this != &other) 
	{
		stack_ = other.stack_;
	}
	return *this;
}

double	RPN::evaluate(const std::string expression)
{
	std::istringstream	iss(expression);

	while (iss >> token_)
		processToken();
	
	if (stack_.size() != 1)
		throw std::runtime_error("Error: invalid");
	
	return stack_.top();
	
}

void	RPN::processToken()
{
	if (isdigit(token_[0]))
		stack_.push(std::atof(token_.c_str()));	
	else if (token_.length() == 1)
		handleOperator();
	else
	{
		throw std::runtime_error("Error: invalid token.");
	}
	
}

void	RPN::handleOperator()
{
	if (stack_.size() < 2)
		throw std::runtime_error("Error: insufficient operands");
	
	double b = stack_.top(); stack_.pop();
	double a = stack_.top(); stack_.pop();
	executeOperation(token_[0], a, b);
}

void	RPN::executeOperation(char mathOperator, double a, double b)
{
	switch (mathOperator)
	{
		case '+':
			stack_.push(a + b);
			break;
		case '-':
			stack_.push(a - b);
			break;
		case '*':
			stack_.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero.");
			stack_.push(a / b);
			break;
		default:
			throw std::runtime_error("Error: invalid operator.");
	}
}
