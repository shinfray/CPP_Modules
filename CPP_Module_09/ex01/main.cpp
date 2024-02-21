/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:10 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/01 16:02:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"inverted Polish mathematical expression\"" << std::endl;
        return 1;
    }
    try
    {
        RPN equation(argv[1]);
        equation.PrintResult();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "." << std::endl;
    }
    
    return 0;
}
