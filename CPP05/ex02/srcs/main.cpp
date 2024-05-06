/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:39:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/07 00:03:05 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <sstream> 

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE "\033[34m"

int main()
{
	std::cout << GREEN << "Test constructors and assignment operator:" << RESET << std::endl;
	std::cout << BLUE << "Test default constructor:" << RESET << std::endl;
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
	for (int i = 0; i < 10; ++i)
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

    std::cout << "Success rate: " << successRate << std::endl;

	std::cout << BLUE << "test unsuccessful executing" << RESET << std::endl;
	
	std::cout << BLUE << "test unsuccessful signing" << RESET << std::endl;


	

	return 0;
}