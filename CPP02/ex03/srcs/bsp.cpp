/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:32:56 by angassin          #+#    #+#             */
/*   Updated: 2024/03/28 11:50:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/*
	In this function, a, b, and c are the vertices of the triangle,
	and point is the point to check. 
	The function calculates the cross products of the vectors formed by the
	triangle's edges and the vectors from the triangle's vertices to the point. 
	Then it checks if all the cross products have the same sign. 
	If they do, the point is inside the triangle; otherwise, it's outside.
*/
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed cross1 = Point::cross(b - a, point - a);
	Fixed cross2 = Point::cross(c - b, point - b);
	Fixed cross3 = Point::cross(a - c, point - c);

	return (Point::sign(cross1) == Point::sign(cross2) && Point::sign(cross2) == Point::sign(cross3));
}
