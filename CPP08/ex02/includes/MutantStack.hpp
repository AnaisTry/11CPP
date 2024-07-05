/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:16:36 by angassin          #+#    #+#             */
/*   Updated: 2024/07/06 00:54:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Default constructor
		MutantStack() : std::stack<T>() 
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}

		// Copy constructor
		MutantStack(MutantStack const &other) : std::stack<T>(other) 
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
			*this = other;
		}

		// Assignment operator
		MutantStack &operator=(MutantStack const &other)
		{
			std::cout << "MutantStack assignment operator called" << std::endl;
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		// Destructor
		virtual ~MutantStack() 
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}

		iterator end()
		{
			return std::stack<T>::c.end();
		}

		private:
			std::stack<T> _stack;
};


#endif