/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:55 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/30 13:09:57by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./btc \"file\"" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc_exchange;
        // btc_exchange.DisplayBtcPrice();
        btc_exchange.ReadInputFile(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "." << std::endl;
        return 1;
    }
    return 0;
}
