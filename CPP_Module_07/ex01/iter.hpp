/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:54:27 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/05 18:22:50 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
# define ITER_HPP_

# include <cstddef>
# include <iostream>

template<typename T, typename F>
void    iter(T* array, size_t size, F f)
{
    if (f == NULL)
        return;
    for (size_t i = 0; i < size; ++i)
        (*f)(array[i]);
}

template<typename T>
void display_data(T& data)
{
    std::cout << data;
}

#endif  // ITER_HPP_
