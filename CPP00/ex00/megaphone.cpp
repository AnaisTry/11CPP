/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:22:56 by angassin          #+#    #+#             */
/*   Updated: 2024/02/21 21:27:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	toupper behavior undefined if the argument passed is not representable as 
	unsigned char and is not equal to EOF
*/
int main(int argc, char **argv)
{

	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string arg(argv[i]);
			for (std::size_t j = 0; j < arg.size(); ++j)
				arg[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(arg[j])));

			std::cout << arg;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return 0;
}