/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:47:04 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/04 12:17:18 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

void    display(int val)
{
    std::cout << val << std::endl;
}

int main()
{
    int     search_into[] = {14, 5, 390, 42, 3, -10};
    int     to_find[] = {390, 3, -10, 2345};

    size_t  search_into_size = sizeof(search_into) / sizeof(*search_into);
    size_t  to_find_size = sizeof(to_find) / sizeof(*to_find);

    {
        std::cout << "========= vector tests ==========" << std::endl;

        std::vector<int>    container;
        for (size_t i = 0; i < search_into_size; ++i)
            container.push_back(search_into[i]);
        std::for_each(container.begin(), container.end(), &display);
        std::cout << std::endl;

        for (size_t i = 0; i < to_find_size; ++i)
            printToFind(container, to_find[i]);
    }
    std::cout << std::endl;
    {
        std::cout << "========= list tests ==========" << std::endl;

        std::list<int>    container;
        for (size_t i = 0; i < search_into_size; ++i)
            container.push_back(search_into[i]);
        std::for_each(container.begin(), container.end(), &display);
        std::cout << std::endl;

        for (size_t i = 0; i < to_find_size; ++i)
            printToFind(container, to_find[i]);
    }

    return 0;
}
