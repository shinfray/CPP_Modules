/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:52:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:22:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "bsp.hpp"

int main()
{
    const Point a(0, 0);
    const Point b(10, 30);
    const Point c(20, 0);
    const Point toFind(10, 15);

    if (bsp(a, b, c, toFind) == true)
        std::cout << "Point is INSIDE the triangle" << std::endl;
    else
        std::cout << "Point is OUTSIDE the triangle" << std::endl;
    return 0;
}
