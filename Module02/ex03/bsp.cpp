/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:35:23 by dogs              #+#    #+#             */
/*   Updated: 2025/12/21 14:44:39 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed cross(Point const & a, Point const& b, Point const& p)
{
    return(b.getX()- a.getX()) * (p.getY() - a.getY())
        - (b.getY() - a.getY()) * (p.getX() - a. getX());
}
bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed c1 = cross(a, b, p);
    Fixed c2 = cross(b, c, p);
    Fixed c3 = cross(c, a, p);

    if (c1 == 0 || c2 == 0 || c3 == 0)
        return false;
    
    bool hasNeg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool hasPos = (c1 > 0) || (c2 > 0) || (c3 > 0);

    return !(hasNeg && hasPos);
}