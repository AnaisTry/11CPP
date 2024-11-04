/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:26 by angassin          #+#    #+#             */
/*   Updated: 2024/11/04 16:38:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>
# include <cstdlib> // atof

class RPN
{
	public:

		RPN();
		virtual ~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		double	evaluate(const std::string expression);

	 private:

		std::stack<double>	stack_;
		std::string			token_;

		void	processToken();
		void	handleOperator();
		void	executeOperation(char mathOperator, double a, double b);
};

#endif