/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:16:35 by angassin          #+#    #+#             */
/*   Updated: 2024/05/07 21:29:02 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"


// Default constructor
PresidentialPardonForm:: PresidentialPardonForm() : AForm("pardonBlankForm", 25, 5){}

// Parameterized constructor
PresidentialPardonForm:: PresidentialPardonForm(const std::string &target) : 
	AForm("presidentialPardonForm", 25, 5), _target(target){}

// Destructor
 PresidentialPardonForm::~ PresidentialPardonForm(){}

// Copy constructor
 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm &other) : AForm(other)
 {
	_target = other._target;
 }

// Assignment operator
 PresidentialPardonForm&  PresidentialPardonForm::operator=(const  PresidentialPardonForm &other) 
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
void  PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const  PresidentialPardonForm &form) 
{
	out << "Form " << form.getName() << ", grade to sign " << form.getSignGrade() 
		<< ", grade to execute " << form.getExecGrade() 
		<< ", is signed : " << (form.isSigned() ? "yes" : "no");
	return out;
}
