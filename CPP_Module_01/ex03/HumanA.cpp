/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:27:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:28:12 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name_(name), weapon_(weapon)
{
}

HumanA::~HumanA()
{
    return;
}

const std::string&  HumanA::getName() const
{
    return name_;
}

const std::string& HumanA::getWeapon() const
{
    return weapon_.getType();
}

void HumanA::attack() const
{
    std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}
