/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:13:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/19 16:43:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return this->fixedPointValue_;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called from " << this->fixedPointValue_;
	std::cout << "to " << other.getRawBits() << std::endl;

	this->FixedPointValue_ = other.getRawBits();

	return *this;
}