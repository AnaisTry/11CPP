/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:26 by angassin          #+#    #+#             */
/*   Updated: 2024/11/04 14:21:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
	public:
		RPN();
		virtual ~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	 protected:
		// Protected members

	 private:
		// Private members
};

#endif