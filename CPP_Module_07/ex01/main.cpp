/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:54:25 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/05 18:40:38 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

#include "iter.hpp"

int display_data_int(const int data)
{
    std::cout << data;
    return 0;
}
void    display_data_str(const std::string& str )
{
	std::cout << str;
}

int main()
{
    const int           int_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const std::string	string_array[] = {"Hello", "world", "how", "are", "you?"};
    const char          sentence[] = "HI!";

    std::cout << "========== iter 1 ===========" << std::endl;
	iter(int_array, sizeof(int_array) / sizeof(*int_array), &display_data<const int>);
    std::cout << std::endl;
    std::cout << "========== iter 2 ===========" << std::endl;
	iter(string_array, 5, &display_data<const std::string>);
    std::cout << std::endl;
    std::cout << "========== iter 3 ===========" << std::endl;
    iter(sentence, sizeof(sentence) / sizeof(*sentence), &display_data<const char>);
    std::cout << std::endl;
    std::cout << "========== iter 4 ===========" << std::endl;
	iter(int_array, sizeof(int_array) / sizeof(int), &display_data_int);
    std::cout << std::endl;
    std::cout << "========== iter 5 ===========" << std::endl;
	iter(string_array, 5, &display_data_str);
    std::cout << std::endl;

    return 0;
}
