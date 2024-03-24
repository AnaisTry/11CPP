/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:13:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/24 19:35:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : fixedPointValue_(intValue << FRACTIONAL_BITS_)
{
	std::cout << "int constructor called" << std::endl;	
}

Fixed::Fixed(const float floatValue) : fixedPointValue_(roundf(floatValue * (1 << FRACTIONAL_BITS_)))
{
	std::cout << "float constuctor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &other)
		this->fixedPointValue_ = other.getRawBits();

	return *this;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue_;
}

float Fixed::toFloat() const
{
	//to do
}

int Fixed::toInt() const
{
	//to check
	return this->fixedPointValue_ >> FRACTIONAL_BITS_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}
