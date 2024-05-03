/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:45:50 by angassin          #+#    #+#             */
/*   Updated: 2024/05/03 17:13:45 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
		// Destructor
		virtual ~Bureaucrat();
		// Copy constructor
		Bureaucrat(const Bureaucrat& other);
		// Assignment operator
		Bureaucrat& operator=(Bureaucrat const& other);

	
		
		// Getters
		const std::string getName() const;
		int getGrade() const;

		//increment and decrement grade

		
	private:
		const std::string _name;
		int _grade;

};
// Overload << operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
