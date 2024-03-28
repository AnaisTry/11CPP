/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:13:17 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 11:25:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>

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
		
	private:
	
		const Fixed x_;
		const Fixed y_;
		
};

# endif
