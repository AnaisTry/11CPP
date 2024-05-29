/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:08:51 by angassin          #+#    #+#             */
/*   Updated: 2024/05/29 18:04:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manip.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d )<< std::endl << std::endl;

	    // Test with integers
    int e = -2147483648, f = 2147483647;
    swap(e, f);
    std::cout << "After swapping, e = " << e << ", f = " << f << std::endl;
    std::cout << "Min of e and f = " << ::min(e, f) << std::endl;
	std::cout << "Max of e and f = " << ::max(e, f) << std::endl << std::endl;

    // Test with floats
    float g = -340282346638528859811704183484516925440.0000000000000000f, h = 340282346638528859811704183484516925440.0000000000000000f;
    swap(g, h);
    std::cout << "After swapping, g = " << g << ", h = " << h << std::endl;
    std::cout << "Min of g and h = " << ::min(g, h) << std::endl;
	std::cout << "Max of g and h = " << ::max(g, h) << std::endl << std::endl;

    // Test with strings
    std::string i = "hello@", j = "#world";
    swap(i, j);
    std::cout << "After swapping, i = " << i << ", j = " << j << std::endl;
    std::cout << "Min of i and j = " << ::min(i, j) << std::endl;
	std::cout << "Max of i and j = " << ::max(i, j) << std::endl << std::endl;

	 // Test with empty strings
    std::string empty1 = "", empty2 = "not empty";
    ::swap(empty1, empty2);
    std::cout << "min( empty1, empty2 ) = " << ::min(empty1, empty2) << std::endl;
    std::cout << "max( empty1, empty2 ) = " << ::max(empty1, empty2) << std::endl << std::endl;

    // Test with same values
    int same1 = 10, same2 = 10;
    ::swap(same1, same2);
    std::cout << "min( same1, same2 ) = " << ::min(same1, same2) << std::endl;
    std::cout << "max( same1, same2 ) = " << ::max(same1, same2) << std::endl << std::endl;


	return 0;
} 