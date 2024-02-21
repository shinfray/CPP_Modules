/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:00 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:29:38 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
    levels_strings_[kDebug] = "DEBUG";
    levels_strings_[kInfo] = "INFO";
    levels_strings_[kWarning] = "WARNING";
    levels_strings_[kError] = "ERROR";
    function_[kDebug] = &Harl::debug;
    function_[kInfo] = &Harl::info;
    function_[kWarning] = &Harl::warning;
    function_[kError] = &Harl::error;
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level)
{
    for (LevelsKey levels_key(kDebug); levels_key < kLevelKeysNumber; levels_key = (LevelsKey)(levels_key + 1))
        if (level == levels_strings_[levels_key])
            return (this->*function_[levels_key])();
    std::cout << "LEVEL NOT RECOGNIZED!!!" << std::endl;
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
