/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:55:18 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 13:50:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Usage: ./a.out \"value\"" << std::endl;
    else
        ScalarConverter::convert(argv[1]);

    return 0;
}
