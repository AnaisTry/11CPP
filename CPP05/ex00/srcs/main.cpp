/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/09 15:26:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	std::cout << GREEN << "Test default constructor:" << RESET << std::endl;
	Bureaucrat b0;
	std::cout << b0 << std::endl << std::endl;
	
	std::cout << GREEN << "Test boundary conditions:" << RESET << std::endl;
	try
	{
		Bureaucrat b1("b1", 150);
		
		std::cout << BLUE << "test getters and overload operator : " << RESET << std::endl;
		std::cout << b1 << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "test b2 grade 0" << RESET << std::endl;
	try
	{
		Bureaucrat b2("b2", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "test b3 grade 151" << RESET << std::endl;
	try
	{
		Bureaucrat b3("b3", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat b4("b4", 1);

		std::cout << BLUE << "test getters and overload operator : " << RESET << std::endl;
		std::cout << b4 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "Test assignment operator" << RESET << std::endl;
    try 
	{
        Bureaucrat b5("b5", 50);
        Bureaucrat b6("b6", 100);
		b6 = b5;  
        std::cout << b6 << std::endl;
    } 
	catch(std::exception& e) 
	{
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;

	std::cout << GREEN << "Test copy constructor b0 in bCopy" << RESET << std::endl;
	try 
	{
		Bureaucrat bCopy = b0;  
		std::cout << bCopy << std::endl;
	} 
	catch(std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::cout << GREEN << "Test increment and decrement" << RESET << std::endl;
    try 
	{
        Bureaucrat b7("b7", 75);
		
		std::cout << BLUE << "test increment : should print a grade of 74 " << RESET << std::endl;
        b7.incrementGrade();
        std::cout << b7 << std::endl; 

		std::cout << BLUE << "test decrement : should print a grade of 75 " << RESET << std::endl;
        b7.decrementGrade();
        std::cout << b7 << std::endl << std::endl;

		std::cout << BLUE << "Test boundary conditions " << RESET << std::endl;
        
		Bureaucrat b8("b8", 1);
		std::cout << BLUE << "Test increment b8 : should throw GradeTooHighException " << RESET << std::endl;
        b8.incrementGrade();   
	} 
	catch(const std::exception& e) 
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	try 
	{
		Bureaucrat b9("b9", 150);
		std::cout << BLUE << "Test decrement b9 : should throw GradeTooLowException " << RESET << std::endl;
		b9.decrementGrade();   
	} 
	catch(const std::exception& e) 
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
		
	return 0;
}