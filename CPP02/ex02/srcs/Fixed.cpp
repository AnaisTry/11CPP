/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:13:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/25 18:14:19 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept> // std::invalid_argument

Fixed::Fixed() : fixedPointValue_(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : fixedPointValue_(intValue << FRACTIONAL_BITS_)
{
	// std::cout << "Int constructor called" << std::endl;	
}

Fixed::Fixed(const float floatValue) : fixedPointValue_(roundf(floatValue * (1 << FRACTIONAL_BITS_)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &other)
		this->fixedPointValue_ = other.getRawBits();

	return *this;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue_;
}

int Fixed::setRawBits(int const raw)
{
	fixedPointValue_ =	raw;
}

float Fixed::toFloat() const
{
	return (float)this->fixedPointValue_ / (1 << FRACTIONAL_BITS_);
}

int Fixed::toInt() const
{
	return this->fixedPointValue_ >> FRACTIONAL_BITS_;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue_ < b.fixedPointValue_)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue_ < b.fixedPointValue_)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue_ > b.fixedPointValue_)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue_ > b.fixedPointValue_)
		return a;
	else
		return b;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->fixedPointValue_ > other.fixedPointValue_;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fixedPointValue_ < other.fixedPointValue_;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixedPointValue_ >= other.fixedPointValue_;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixedPointValue_ <= other.fixedPointValue_;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fixedPointValue_ == other.fixedPointValue_;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixedPointValue_ != other.fixedPointValue_;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}	

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
		throw std::invalid_argument("Division by zero");
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->fixedPointValue_++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->fixedPointValue_--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}


std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

