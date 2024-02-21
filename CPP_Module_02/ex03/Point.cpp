/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:17 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:14:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) : x_(x), y_(y)
{
}

Point::Point(const Point& src) : x_(src.getX()), y_(src.getY())
{
}

Point::~Point()
{
}

const Fixed&    Point::getX() const
{
    return x_;
}

const Fixed&    Point::getY() const
{
    return y_;
}
