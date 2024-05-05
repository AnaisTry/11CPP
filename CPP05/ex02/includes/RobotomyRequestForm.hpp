/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:28 by angassin          #+#    #+#             */
/*   Updated: 2024/05/05 18:21:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
	public:
		 RobotomyRequestForm();
		 RobotomyRequestForm(const std::string &target);
		 virtual ~ RobotomyRequestForm();
		 RobotomyRequestForm(const  RobotomyRequestForm& other);
		 RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		//  void execute(const Bureaucrat &executor) const;


	 private:
		// Private members
};

#endif
