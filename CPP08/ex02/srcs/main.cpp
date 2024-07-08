/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:51 by angassin          #+#    #+#             */
/*   Updated: 2024/07/08 15:35:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
# include <list>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
	// test mutanstack
	
	std::cout << GREEN << "Test default constructor" << RESET << std::endl;
	MutantStack<int> mstack;
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

	// test list

	std::cout << GREEN << "Test default constructor" << RESET << std::endl;
	std::list<int> lst;
	std::cout << std::endl << GREEN << "Test push_back, pop, top and size" << RESET << std::endl;
	std::cout << BLUE << "push_back and top" << RESET << std::endl;
	lst.push_back(5);
	std::cout << "add number : " << lst.top() << std::endl; 
	lst.push_back(17);
	std::cout << "add number : " << lst.top() << std::endl;
	std::cout << "number on the top of the list : "<< lst.top() << std::endl;
	std::cout << BLUE << "pop and size" << RESET << std::endl;
	lst.pop();
	std::cout << "the size of the lst is now : "<< lst.size() << std::endl;
	lst.push_back(3);
	std::cout << "add number : " << lst.top() << std::endl;
	lst.push_back(5);
	std::cout << "add number : " << lst.top() << std::endl;
	lst.push_back(737);
	std::cout << "add number : " << lst.top() << std::endl;
	lst.push_back(0);
	std::cout << "add number : " << lst.top() << std::endl;

	std::cout << std::endl << GREEN << "Test iterators" << RESET << std::endl;
	list<int>::iterator it = lst.begin();
	list<int>::iterator ite = lst.end();
	std::cout << BLUE << "Increment and decrement" << RESET << std::endl;
	++it;
	--it;
	std::cout << "The numbers in the lst are:" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}	

	std::cout << std::endl << GREEN << "Test copy constructor and assignment operator" << RESET << std::endl;
	std::cout << BLUE << "mutantStack copy constructor" << RESET << std::endl;
	list<int> lcopy(lst);

	std::cout << BLUE << "inherited list copy constructor" << RESET << std::endl;
	lst.push_back(1);
	std::list<int> s(lst);
	std::cout << s.top() << std::endl;

	return 0;
}	