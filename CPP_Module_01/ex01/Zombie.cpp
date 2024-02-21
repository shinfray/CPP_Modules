/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:27:13 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) : name_("<name>")
{
}

Zombie::Zombie(std::string& name) : name_(name)
{
}

Zombie::~Zombie()
{
    std::cout << get_name() << ": Destroyed" << std::endl;
}

const std::string&  Zombie::get_name() const
{
    return name_;
}

void    Zombie::set_name(const std::string& name)
{
    name_ = name;
}

void    Zombie::announce() const
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
