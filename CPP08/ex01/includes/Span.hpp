/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:20:10 by angassin          #+#    #+#             */
/*   Updated: 2024/07/05 11:03:57 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <set>

class Span
{
	public:
		Span();
		Span(unsigned int maxN);
		virtual ~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int number);
		void addRange(size_t rangeSize);
		void printContainer() const;
		size_t shortestSpan() const;
		size_t longestSpan() const;


	 private:
		unsigned int maxN_;
		std::multiset<int> container_;
};

#endif
