/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:12:02 by angassin          #+#    #+#             */
/*   Updated: 2024/03/26 10:54:08 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;

	 // Test arithmetic operators
    Fixed c = a + b;
    std::cout << "a + b = " << c << std::endl;


    c = a - b;
    std::cout << "a - b = " << c << std::endl;

    c = a * b;
    std::cout << "a * b = " << c << std::endl;

    c = a / b;
    std::cout << "a / b = " << c << std::endl;

    // Test comparison operators
    std::cout << "a > b: " << std::boolalpha << (a > b) << std::endl;
    std::cout << "a < b: " << std::boolalpha << (a < b) << std::endl;
    std::cout << "a >= b: " << std::boolalpha << (a >= b) << std::endl;
    std::cout << "a <= b: " << std::boolalpha << (a <= b) << std::endl;
    std::cout << "a == b: " << std::boolalpha << (a == b) << std::endl;
    std::cout << "a != b: " << std::boolalpha << (a != b) << std::endl;

    // Test increment/decrement operators
    ++a;
    std::cout << "++b = " << b << std::endl;
    
    --a;
    std::cout << "--b = " << b << std::endl;

    a++;
    std::cout << "b++ = " << b << std::endl;

    a--;
    std::cout << "b-- = " << b << std::endl;

    // Test setRawBits
    std::cout << "a in raw bits: "<< a.getRawBits() << std::endl;
    std::cout << "set a raw bits to 5" << std::endl;
    a.setRawBits(5);
    std::cout << "a in raw bits: "<< a.getRawBits() << std::endl;
    std::cout << "a is " << a << std::endl; 
	
	return 0;
}
