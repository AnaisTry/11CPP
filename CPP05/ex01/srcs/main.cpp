/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/04 12:55:52 by angassin         ###   ########.fr       */
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
	
	std::cout << GREEN << "Test boundary conditions:" << RESET << std::endl;
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

	// std::cout << BLUE << "test f2 grade 0" << RESET << std::endl;
	// try
	// {
	// 	Form f2("f2", 0);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// std::cout << BLUE << "test f3 grade 151" << RESET << std::endl;
	// try
	// {
	// 	Form f3("f3", 151);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// try
	// {
	// 	Form f4("f4", 1);

	// 	std::cout << BLUE << "test getters and overload << : " << RESET << std::endl;
	// 	std::cout << f4 << std::endl;
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	
	// std::cout << GREEN << "Test assignment operator" << RESET << std::endl;
    // try 
	// {
    //     Form f5("f5", 50);
    //     Form f6("f6", 100);
	// 	f6 = f5;  
    //     std::cout << f6 << std::endl;
    // } 
	// catch(std::exception& e) 
	// {
    //     std::cerr << e.what() << '\n';
    // }
	// std::cout << std::endl;

	// std::cout << GREEN << "Test copy constructor f0 in fCopy" << RESET << std::endl;
	// try 
	// {
	// 	Form fCopy = f0;  
	// 	std::cout << fCopy << std::endl;
	// } 
	// catch(std::exception& e) 
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;


	// std::cout << GREEN << "Test increment and decrement" << RESET << std::endl;
    // try 
	// {
    //     Form f7("f7", 75);
		
	// 	std::cout << BLUE << "test increment : should print a grade of 74 " << RESET << std::endl;
    //     f7.incrementGrade();
    //     std::cout << f7 << std::endl; 

	// 	std::cout << BLUE << "test decrement : should print a grade of 75 " << RESET << std::endl;
    //     f7.decrementGrade();
    //     std::cout << f7 << std::endl << std::endl;

	// 	std::cout << BLUE << "Test foundary conditions " << RESET << std::endl;
        
	// 	Form f8("f8", 1);
	// 	std::cout << BLUE << "Test increment f8 : should throw GradeTooHighException " << RESET << std::endl;
    //     f8.incrementGrade();   
	// } 
	// catch(const std::exception& e) 
	// {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }

	// try 
	// {
	// 	Form f9("f9", 150);
	// 	std::cout << BLUE << "Test decrement f9 : should throw GradeTooLowException " << RESET << std::endl;
	// 	f9.decrementGrade();   
	// } 
	// catch(const std::exception& e) 
	// {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }
		
	return 0;
}