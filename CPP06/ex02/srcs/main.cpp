/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:13:29 by angassin          #+#    #+#             */
/*   Updated: 2024/05/24 15:26:04 by angassin         ###   ########.fr       */
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
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) std::cout << "A\n";
	else if  (dynamic_cast<B*>(p)) std::cout << "B\n";
	else if  (dynamic_cast<C*>(p)) std::cout << "C\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (std::bad_cast&) {}
}

int main()
{
	srand(time(NULL));
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
