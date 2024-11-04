/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:21 by angassin          #+#    #+#             */
/*   Updated: 2024/11/04 14:29:46 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage : " << argv[0] << " \"Expression\"" << '\n';
		return 1;
	}

	try
	{
		RPN	rpn;
		double	result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}