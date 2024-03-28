/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:26:08 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 11:30:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Point::Point() : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) : x_(x), y_(y)
{
}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_)
{
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		x_ = other.x_;
		y_ = other.y_;
	}
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
