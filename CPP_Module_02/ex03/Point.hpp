/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:51 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:21:55 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
# define POINT_HPP_

# include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& src);

        ~Point();

        const Fixed&    getX() const;
        const Fixed&    getY() const;

    private:
        Point&  operator=(const Point& rhs);

        const Fixed x_;
        const Fixed y_;
};


#endif  // POINT_HPP_
