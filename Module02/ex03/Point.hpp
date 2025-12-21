/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:23:03 by dogs              #+#    #+#             */
/*   Updated: 2025/12/21 14:27:56 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
Point();
Point(const float x, const float y);
Point(const Point& other);
Point& operator=(const Point& other);
~Point();

Fixed getX() const;
Fixed getY() const;
};

#endif