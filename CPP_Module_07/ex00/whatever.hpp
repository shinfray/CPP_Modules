/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:38:00 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/05 18:32:52 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

template<typename T>
void    swap(T& a, T& b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template<typename T>
const T&    min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template< typename T>
const T&    max(const T& a, const T& b)
{
    return (a > b ? a : b);
}

#endif  // WHATEVER_HPP_
