/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/09 16:49:39 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#include <sstream> 

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	std::cout << GREEN << "Test constructors :" 
		<< RESET << std::endl << std::endl;
	std::cout << BLUE << "Test default constructor:" << RESET << std::endl;
	ShrubberyCreationForm s0;
	RobotomyRequestForm r0;
	PresidentialPardonForm p0;
	std::cout << s0 << std::endl;
	std::cout << r0 << std::endl;
	std::cout << p0 << std::endl << std::endl;

	std::cout << BLUE << "Test parameterized constructor:" << RESET << std::endl;
	ShrubberyCreationForm s1("Garden");	
	RobotomyRequestForm r1("Narval");
	PresidentialPardonForm p1("Innocent");
	std::cout << s1 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << p1 << std::endl << std::endl;


	std::cout << GREEN << "test signing and executing form" << RESET << std::endl
		<< std::endl;
	std::cout << BLUE << "test successful" << RESET << std::endl;
	Bureaucrat b;
	Bureaucrat b0("b0", 137);
	Bureaucrat b1("b1", 45);
	b0.signForm(s1);
	std::cout << s1 << std::endl;
	b0.executeForm(s1);
	std::cout << std::endl;
	
	b1.signForm(r1);
	std::cout << r1 << std::endl;
	for (int i = 0; i < 6; ++i)
		b1.executeForm(r1);
	std::cout << std::endl;

	const int numTrials = 10000;
    int numSuccesses = 0;

    for (int i = 0; i < numTrials; ++i) {
        std::ostringstream oss;
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        b1.executeForm(r1);

        std::cout.rdbuf(oldCoutStreamBuf);
        std::string result = oss.str();

        if (result.find("has been robotomized successfully") != std::string::npos)
            ++numSuccesses;
    }

    double successRate = static_cast<double>(numSuccesses) / numTrials;

    std::cout << "Success rate: " << successRate << std::endl << std::endl;

	std::cout << std::endl << BLUE << "test signing" << RESET << std::endl;
	std::cout << b.getName() << " grade is " << b.getGrade() << std::endl;
	try{ b.signForm(s1); } catch(const std::exception &e){}
	try{ b.signForm(r1); } catch(const std::exception &e){}
	std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;
	try{b1.signForm(p1); } catch(const std::exception &e){}
	std::cout << std::endl;
	
	for (int i = 0; i < 20; ++i)
		b1.incrementGrade();
	std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;
	b1.signForm(s1);
	b1.signForm(r1);
	b1.signForm(p1);
	


	std::cout << std::endl << BLUE << "test executing" << RESET << std::endl;
	std::cout << b.getName() << " grade is " << b.getGrade() << std::endl;
	b.executeForm(s1);
	b.executeForm(r1);
	std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;
	b1.executeForm(p1);
	std::cout << std::endl;
	
	for (int i = 0; i < 20; ++i)
		b1.incrementGrade();
	std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;
	b1.executeForm(s1);	
	b1.executeForm(r1);
	b1.executeForm(p1);	
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "Test copy constructor and assignment operator:" << RESET 
		<< std::endl << std::endl;
	std::cout << BLUE << "Test assignment operator :" << RESET << std::endl;
	ShrubberyCreationForm s2("Patio");
	s1 = s2;
	b1.signForm(s1);
	b1.executeForm(s1);
	std::cout << std::endl;

	RobotomyRequestForm r2("Donkey");
	r1 = r2;
	b1.signForm(r1);
	b1.executeForm(r1);
	std::cout << std::endl;

	PresidentialPardonForm p2("Guilty");
	p1 = p2;
	b1.signForm(p1);
	b1.executeForm(p1);

	std::cout << std::endl << BLUE << "Test copy constructor and unsigned forms execution:"
		<< RESET << std::endl;
	ShrubberyCreationForm s3(s0);
	b1.executeForm(s3); // not signed
	b1.signForm(s3);
	b1.executeForm(s3); // creates "_shrubbery" file
	std::cout << std::endl;

	RobotomyRequestForm r4("Human");
	RobotomyRequestForm r3(r4);  
	b1.executeForm(r3); // not signed
	b1.signForm(r3);
	b1.executeForm(r3);
	std::cout << std::endl;

	PresidentialPardonForm p4("Fool");
	PresidentialPardonForm p3(p4);
	b1.executeForm(p3); // not signed
	b1.signForm(p3);
	b1.executeForm(p3);
	std::cout << std::endl << std::endl;


	return 0;
}