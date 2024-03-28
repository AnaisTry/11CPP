/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:13:17 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 12:16:36 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
class Point
{
	public:
		Point(); // default constructor
		Point(const float x, const float y); // parameterized constructor
		Point(const Point& other); // copy constructor
		Point& operator=(const Point& other); // copy asssignment operator overload
		~Point(); // destructor

		Fixed getX() const;
		Fixed getY() const;
		static Fixed cross(const Point& p1, const Point& p2);
		static int sign(const Fixed& num);

		Point operator-(const Point& other) const;
		
	private:
	
		const Fixed x_;
		const Fixed y_;
		
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

# endif
