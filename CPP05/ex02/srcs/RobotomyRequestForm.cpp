/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:16:35 by angassin          #+#    #+#             */
/*   Updated: 2024/05/05 18:28:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"


// Default constructor
 RobotomyRequestForm:: RobotomyRequestForm() : AForm("robotomyBlankForm", 72, 45){}

// Parameterized constructor
 RobotomyRequestForm:: RobotomyRequestForm(const std::string &target) : 
	AForm(target, 72, 45){}

// Destructor
 RobotomyRequestForm::~ RobotomyRequestForm() 
{
	// std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

// // Copy constructor
//  RobotomyRequestForm:: RobotomyRequestForm(const  RobotomyRequestForm &other) : _name(other._name), _signed(other._signed), 
// 	_signGrade(other._signGrade), _execGrade(other._execGrade) 
// {
// 	std::cout << "Form " << _name << " copy constructor called" << std::endl;
// 	*this = other;
// }

// // Assignment operator
//  RobotomyRequestForm&  RobotomyRequestForm::operator=(const  RobotomyRequestForm &other) 
// {
// 	std::cout << "Form assignment operator called" << std::endl;
// 	if (this != &other) 
// 	{
// 		_signed = other._signed;
// 	}
		
// 	return *this;
// }





// // Overload << operator
// std::ostream& operator<<(std::ostream &out, const  RobotomyRequestForm &form) 
// {
// 	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
// 		<< ", grade to execute " << form.getExecGrade() 
// 		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
// 	return out;
// }