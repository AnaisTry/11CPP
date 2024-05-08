/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ShrubberyCreationForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:28 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYREQUESTFORM
# define SHRUBBERYREQUESTFORM

# include "AForm.hpp"
// rand()
# include <cstdlib>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		 virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		 void executeAction() const;


	 private:
		std::string _target;
};

#endif
