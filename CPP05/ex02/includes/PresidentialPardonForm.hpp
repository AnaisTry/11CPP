/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:28 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

// rand()
# include <cstdlib>

class  PresidentialPardonForm : public AForm
{
	public:
		 PresidentialPardonForm();
		 PresidentialPardonForm(const std::string& target);
		 virtual ~ PresidentialPardonForm();
		 PresidentialPardonForm(const  PresidentialPardonForm& other);
		 PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		 void executeAction() const;


	 private:
		std::string _target;
};

#endif
