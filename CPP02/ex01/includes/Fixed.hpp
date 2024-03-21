/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:13:40 by angassin          #+#    #+#             */
/*   Updated: 2024/03/21 16:11:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(); // default constructor
		Fixed(const Fixed &other); // copy constructor
		Fixed &operator=(const Fixed &other); // copy asssignment operator overload
		~Fixed(); // destructor

		int getRawBits() const;
		void setRawBits(int const raw);
		
	private:
	
		int fixedPointValue_;
		static const int FRACTIONAL_BITS_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
#endif