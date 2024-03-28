/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:26:08 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 12:21:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) : x_(x), y_(y)
{
}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_)
{
}

// The copy assignment operator is not implemented because the class has const members.
Point& Point::operator=(const Point& /*other*/)
{
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return x_;
}

Fixed Point::getY() const
{
	return y_;
}

/*
	The formula for the cross product of two 2D vectors (x1, y1) and (x2, y2) is x1*y2 - y1*x2. 
	This formula calculates the area of the parallelogram formed by the two vectors. 
	If the result is positive, the second vector is counterclockwise from the first vector. 
	If the result is negative, the second vector is clockwise from the first vector. 
	If the result is zero, the vectors are collinear.
	In the context of the bsp function, the cross function is used to determine
	the relative orientation of the vectors formed by the triangle's vertices and the point. 
	This information is used to check if the point is inside the triangle.
*/
Fixed Point::cross(const Point& p1, const Point& p2)
{
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}

int Point::sign(const Fixed& num)
{
	if (num > 0)
		return 1;
	else if (num < 0)
		return -1;
	return 0;
}

Point Point::operator-(const Point& other) const
{
	return Point((x_ - other.x_).toFloat(), (y_ - other.y_).toFloat());
}
