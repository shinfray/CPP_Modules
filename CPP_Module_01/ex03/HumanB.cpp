/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:02 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:32:57 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL)
{
}

HumanB::~HumanB()
{
}

const std::string&  HumanB::getName() const
{
    return name_;
}

std::string HumanB::getWeapon() const
{
    std::string result("");

    if (weapon_ != NULL)
        result = weapon_->getType();
    return result;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    weapon_ = &weapon;
    return ;
}

void    HumanB::attack() const
{
	if (weapon_ != NULL)
		std::cout << getName() << " attacks with their " << getWeapon();
	else
		std::cout << getName() << " has no weapon";
    std::cout << std::endl;
}
