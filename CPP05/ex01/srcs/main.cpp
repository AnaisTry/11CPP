/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/09 16:35:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	std::cout << GREEN << "Test default constructor:" << RESET << std::endl;
	Form f0;
	std::cout << f0 << std::endl << std::endl;
	
	std::cout << GREEN << "Test boundary conditions for constructor:" << RESET << std::endl;
	try
	{
		Form f1("f1", 150, 1);
		
		std::cout << BLUE << "test getters and overload << : " << RESET << std::endl;
		std::cout << f1 << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "test f2 grade to sign 151, grade to execute 1" << RESET << std::endl;
	try
	{
		Form f2("f2", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "test f3 to sign 150, grade to execute 0" << RESET << std::endl;
	try
	{
		Form f3("f3", 150, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN << "Test signing forms : " << RESET << std::endl;
	
    Form form("Form1", 40, 30);
 
	std::cout << std::endl << BLUE 
		<< "Test that the bureaucrat cannot sign the form if his grade is too low:" << RESET << std::endl;
	Bureaucrat bureaucrat("John", 50);
    try 
	{
        bureaucrat.signForm(form);
    } catch (const std::exception &e){}

	std::cout << std::endl << BLUE << "Test that the bureaucrat can sign the form if his grade is high enough:" 
		<< RESET << std::endl;
    Bureaucrat bureaucrat2("Jane", 30);
    try 
	{
        bureaucrat2.signForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception &e) 
	{
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;
		
	return 0;
}