/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:16:35 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"


// Default constructor
RobotomyRequestForm:: RobotomyRequestForm() : AForm("robotomyBlankForm", 72, 45){}

// Parameterized constructor
RobotomyRequestForm:: RobotomyRequestForm(const std::string &target) : 
	AForm(target, 72, 45), _target(target){}

// Destructor
 RobotomyRequestForm::~ RobotomyRequestForm(){}

// Copy constructor
 RobotomyRequestForm:: RobotomyRequestForm(const  RobotomyRequestForm &other) : AForm(other)
 {
	_target = other._target;
 }

// Assignment operator
 RobotomyRequestForm&  RobotomyRequestForm::operator=(const  RobotomyRequestForm &other) 
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
void  RobotomyRequestForm::executeAction() const
{
	std::cout << "drrrrrrrr... " << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const  RobotomyRequestForm &form) 
{
	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
		<< ", grade to execute " << form.getExecGrade() 
		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
	return out;
}
