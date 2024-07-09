/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:16:36 by angassin          #+#    #+#             */
/*   Updated: 2024/07/09 17:45:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		// Default constructor
		MutantStack() : std::stack<T, std::deque<T> >() 
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}

		// Copy constructor
		MutantStack(MutantStack const &other) : std::stack<T, std::deque<T> >(other) 
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
			*this = other;
		}

		// Assignment operator
		MutantStack &operator=(MutantStack const &other)
		{
			std::cout << "MutantStack assignment operator called" << std::endl;
			if (this != &other)
				std::stack<T, std::deque<T> >::operator=(other);
			return *this;
		}

		// Destructor
		virtual ~MutantStack() 
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}

		// Iterators
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		// Member functions

		// void empty()
		// {
		// 	return this->c.empty();
		// }

		// size_t size()
		// {
		// 	return this->c.size();
		// }

		// T top()
		// {
		// 	return this->c.back();
		// }
		
		// void push(T value)
		// {
		// 	this->c.push_back(value);
		// }

		// void pop()
		// {
		// 	this->c.pop_back();
		// }
};

#endif
