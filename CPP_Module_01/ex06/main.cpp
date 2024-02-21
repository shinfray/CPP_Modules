/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:04 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/11 21:43:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./Harl_filter \"LEVEL\"" << std::endl;
        return 1;
    }

    Harl    harl;

    harl.complain(argv[1]);
    return 0;
}
