/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/06 18:07:24 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	std::cout << GREEN << "Test default constructor:" << RESET << std::endl;
	RobotomyRequestForm r0;
	std::cout << r0 << std::endl << std::endl;
	RobotomyRequestForm r1("r1");
	std::cout << r1 << std::endl << std::endl;

	r0 = r1;
	std::cout << r0 << std::endl << std::endl;
	RobotomyRequestForm r2(r1);
	std::cout << r2 << std::endl << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "test signing and executing form" << RESET << std::endl;
	std::cout << BLUE << "test successful" << RESET << std::endl;
		Bureaucrat b1("b1", 45);
		b1.signForm(r1);
		std::cout << r1 << std::endl;
		b1.executeForm(r1);
	std::cout << std::endl;

	std::cout << BLUE << "test unsuccessful executing" << RESET << std::endl;
	try
	{
		r1.beSigned(Bureaucrat("b1", 72));
		std::cout << r1 << std::endl;
		r1.execute(Bureaucrat("b3", 46));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << BLUE << "test unsuccessful signing" << RESET << std::endl;


	

	return 0;
}