/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:54:00 by angassin          #+#    #+#             */
/*   Updated: 2024/05/04 12:57:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form 
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
		Form();
		Form(const std::string &name, const int _signGrade, const int _execGrade);
		// Copy constructor
		Form(const Form &other);
		// Destructor
		virtual ~Form();
		
		// Assignment operator
		Form& operator=(const Form &other);

	
		
		// Getters
		const std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

};
// Overload << operator
std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
