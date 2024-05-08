/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:04:26 by angassin          #+#    #+#             */
/*   Updated: 2024/05/08 15:31:06 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		virtual ~Intern();
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& formName, const std::string& target);

	private:
		AForm* createShrubberyCreationForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);

		typedef AForm* (Intern::*formCreator)(const std::string& target);
		struct FormType
		{
			std::string name;
			formCreator creator;
		};
		static const FormType _formTypes[];
};

#endif
