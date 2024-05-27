/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:13:29 by angassin          #+#    #+#             */
/*   Updated: 2024/05/27 16:29:46 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL) std::cout << "A\n";
	else if  (dynamic_cast<B*>(p) != NULL) std::cout << "B\n";
	else if  (dynamic_cast<C*>(p) != NULL) std::cout << "C\n";
}

void identify(Base& p) 
{
    try 
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (std::exception&) {}
    try 
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (std::exception&) {}
    try 
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (std::exception&) {}
}

int main()
{
	srand(time(NULL)); // Seed the random number generator
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
