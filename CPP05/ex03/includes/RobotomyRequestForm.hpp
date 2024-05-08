/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:28 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
// rand()
# include <cstdlib>

class  RobotomyRequestForm : public AForm
{
	public:
		 RobotomyRequestForm();
		 RobotomyRequestForm(const std::string &target);
		 virtual ~ RobotomyRequestForm();
		 RobotomyRequestForm(const  RobotomyRequestForm& other);
		 RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		 void executeAction() const;


	 private:
		std::string _target;
};

#endif
