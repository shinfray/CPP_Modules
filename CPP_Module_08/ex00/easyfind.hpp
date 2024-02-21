/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:46:36 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/04 12:01:40 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <algorithm>

template<typename T>
typename T::const_iterator  easyfind(const T& container, const int value)
{
    return std::find<typename T::const_iterator, int>(container.begin(), container.end(), value);
}

template<typename T>
void    printToFind(const T& container, const int to_find)
{
        std::cout << "to find: " << to_find << std::endl;
        typename T::const_iterator  it = easyfind(container, to_find);
        if (it != container.end())
            std::cout << "value found: " << *it << std::endl;
        else
            std::cout << "value not found" << std::endl;
}

#endif  // EASYFIND_HPP_
