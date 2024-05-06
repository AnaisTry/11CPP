/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:45:50 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:47:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

class AForm;
class Bureaucrat 
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
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		// Copy constructor
		Bureaucrat(const Bureaucrat &other);
		// Destructor
		virtual ~Bureaucrat();
		
		// Assignment operator
		Bureaucrat& operator=(const Bureaucrat &other);

		// Getters
		const std::string getName() const;
		int getGrade() const;

		// Member functions
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		
	private:	
		const std::string _name;
		int _grade;

};
// Overload << operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
