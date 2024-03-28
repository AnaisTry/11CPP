/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:12:02 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 11:59:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) 
{
    Point a(0, 0);
    Point b(1, 0);
    Point c (0, 1);
    Point p(0.5, 0.5);

    if (bsp(a, b, c, p))
        std::cout << "Test passed : The point is inside the triangle." << std::endl;
    else
        std::cout << "Test failed : The point should be inside the triangle." << std::endl;

    Point p2(1.5, 1.5);

    if (!bsp(a, b, c, p2))
        std::cout << "Test passed : The point is outside the triangle." << std::endl;
    else
        std::cout << "Tests failed : The point should be outside the triangle." << std::endl;


	return 0;
}
