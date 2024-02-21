/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:00 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:34:19 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl()
{
    levels_strings_[kDebug] = "DEBUG";
    levels_strings_[kInfo] = "INFO";
    levels_strings_[kWarning] = "WARNING";
    levels_strings_[kError] = "ERROR";
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level)
{
	LevelsKey   levels_key(kDebug);

    for (; levels_key < kLevelKeysNumber && level != levels_strings_[levels_key]; levels_key = (LevelsKey)(levels_key + 1))
        ;
    switch (levels_key) {
        case kDebug:
            debug();
        case kInfo:
            info();
        case kWarning:
            warning();
        case kError:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}
