/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:51 by angassin          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:37 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
# include <list>
# include <limits>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
	// test mutanstack
	
	std::cout << GREEN << "Test mutantStack default constructor" << RESET << std::endl;
	MutantStack<int> mstack;
	std::cout << mstack.size() << std::endl;
	try{
		std::cout << mstack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	
	}
	std::cout << std::endl << GREEN << "Test push, pop, top and size" << RESET << std::endl;
	std::cout << BLUE << "push and top" << RESET << std::endl;
	mstack.push(5);
	std::cout << "add number : " << mstack.top() << std::endl; 
	mstack.push(17);
	std::cout << "add number : " << mstack.top() << std::endl;
	std::cout << "number on the top of the stack : "<< mstack.top() << std::endl;
	std::cout << BLUE << "pop and size" << RESET << std::endl;
	mstack.pop();
	std::cout << "the size of the mstack is now : "<< mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "add number : " << mstack.top() << std::endl;
	mstack.push(5);
	std::cout << "add number : " << mstack.top() << std::endl;
	mstack.push(737);
	std::cout << "add number : " << mstack.top() << std::endl;
	mstack.push(0);
	std::cout << "add number : " << mstack.top() << std::endl;
	mstack.push(INT_MAX);
	std::cout << "add number : " << mstack.top() << std::endl;
	mstack.push(INT_MIN);	

	std::cout << std::endl << GREEN << "Test iterators" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << BLUE << "Increment and decrement" << RESET << std::endl;
	++it;
	--it;
	std::cout << "The numbers in the mstack are:" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}	

	std::cout << std::endl << GREEN << "Test copy constructor and assignment operator" << RESET << std::endl;
	std::cout << BLUE << "mutantStack copy constructor" << RESET << std::endl;
	MutantStack<int> scopy(mstack);

	std::cout << BLUE << "inherited stack copy constructor" << RESET << std::endl;
	mstack.push(1);
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;

	// compare with list

	std::cout<< std::endl << GREEN << "Test list default constructor" << RESET << std::endl;
	std::list<int> lst;
	std::cout << std::endl << GREEN << "Test push_back, pop_back, back and size" << RESET << std::endl;
	std::cout << BLUE << "push_back and back" << RESET << std::endl;
	lst.push_back(5);
	std::cout << "add number : " << lst.back() << std::endl; 
	lst.push_back(17);
	std::cout << "add number : " << lst.back() << std::endl;
	std::cout << "number on the back of the list : "<< lst.back() << std::endl;
	std::cout << BLUE << "pop_back and size" << RESET << std::endl;
	lst.pop_back();
	std::cout << "the size of the lst is now : "<< lst.size() << std::endl;
	lst.push_back(3);
	std::cout << "add number : " << lst.back() << std::endl;
	lst.push_back(5);
	std::cout << "add number : " << lst.back() << std::endl;
	lst.push_back(737);
	std::cout << "add number : " << lst.back() << std::endl;
	lst.push_back(0);
	std::cout << "add number : " << lst.back() << std::endl;
	std::cout << "add number : " << lst.back() << std::endl;
	lst.push_back(INT_MAX);
	std::cout << "add number : " << lst.back() << std::endl;
	lst.push_back(INT_MIN);

	std::cout << std::endl << GREEN << "Test iterators" << RESET << std::endl;
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	std::cout << BLUE << "Increment and decrement" << RESET << std::endl;
	++lit;
	--lit;
	std::cout << "The numbers in the lst are:" << std::endl;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}	

	std::cout << std::endl << GREEN << "Test copy constructor and assignment operator" << RESET << std::endl;
	std::cout << BLUE << "list copy constructor" << RESET << std::endl;
	lst.push_back(1);
	std::list<int> l(lst);
	std::cout << l.back() << std::endl;

	return 0;
}	