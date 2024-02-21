/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:35 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 15:48:20 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

#include <iostream>

static Fixed	area(const Point& a, const Point& b, const Point& c);
static Fixed	abs(Fixed x);

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed   origin_area = abs(area(a, b, c));
    Fixed   first_piece_area = abs(area(point, a, b));
    Fixed   second_piece_area = abs(area(point, b, c));
    Fixed   third_piece_area = abs(area(point, c, a));

    if (origin_area == 0 || first_piece_area == 0 || second_piece_area == 0 || third_piece_area == 0)
        return false;
    return (origin_area == first_piece_area + second_piece_area + third_piece_area);
}

static Fixed    area(const Point& a, const Point& b, const Point& c)
{
    return (((a.getX() * (b.getY() - c.getY())) +
             (b.getX() * (c.getY() - a.getY())) +
             (c.getX() * (a.getY() - b.getY()))) / 2);
}

static Fixed    abs(Fixed value)
{
    if (value < 0)
        return value * -1;
    return value;
}
