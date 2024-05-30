/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:04:23 by angassin          #+#    #+#             */
/*   Updated: 2024/05/30 13:50:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main()
{
	std::string array[] = {"Hello", "World", "!"};
	iter(array, 3, print);
	std::cout << std::endl;

	int array2[] = {1, 2, 3};
	iter(array2, 3, addOne);
	std::cout << std::endl;

	float array3[] = {1.1, 2.2, 3.3};
	iter(array3, 3, addOne);
	
	return 0;
}
