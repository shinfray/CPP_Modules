/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:11 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:24:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& weapon) : type_(weapon)
{
}

Weapon::~Weapon()
{
}

const std::string&  Weapon::getType() const
{
    return type_;
}

void    Weapon::setType(const std::string& weapon)
{
    type_ = weapon;
}
