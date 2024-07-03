/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:20:10 by angassin          #+#    #+#             */
/*   Updated: 2024/07/03 11:42:02 by angassin         ###   ########.fr       */
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

	 private:
		unsigned int maxN_;
		std::multiset<int> container_;
};

#endif
