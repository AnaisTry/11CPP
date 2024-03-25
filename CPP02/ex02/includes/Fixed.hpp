/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:13:40 by angassin          #+#    #+#             */
/*   Updated: 2024/03/25 11:55:11 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(); // default constructor
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other); // copy constructor
		Fixed& operator=(const Fixed& other); // copy asssignment operator overload
		~Fixed(); // destructor

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		// static Fixed& min(Fixed& a, Fixed& b);
		// static const Fixed& min(const Fixed& a, const Fixed& b);
		// static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
	private:
	
		int fixedPointValue_;
		static const int FRACTIONAL_BITS_ = 8;
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);
// std::ostream& operator>()
#endif