/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:54:00 by angassin          #+#    #+#             */
/*   Updated: 2024/05/04 20:32:17 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;
class AForm 
{
	public:

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Constructors
		AForm();
		AForm(const std::string &name, const int _signGrade, const int _execGrade);
		// Copy constructor
		AForm(const AForm &other);
		// Destructor
		virtual ~AForm();
		
		// Assignment operator
		AForm& operator=(const AForm &other);
		
		// Getters
		const std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		// Member functions
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;
		virtual void executeAction() const = 0;
		
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

};
// Overload << operator
std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif
