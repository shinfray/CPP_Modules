/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:19:52 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:20:43 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap Parametized constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& src)
{
    std::cout << "FragTrap Copy constructor from " << src.getName() << std::endl;
    *this = src;
}

FragTrap&   FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap Copy assignment constructor from " << rhs.getName() << std::endl;
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setMaxHitPoints(rhs.getMaxHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Default destructor for " << getName() << std::endl;
}

void    FragTrap::highFivesGuys()
{
    if (getHitPoints() > 0)
        std::cout << "FragTrap send a positive high fives request" << std::endl;
    else
        std::cout << "FrapTrap is dead and can't send a positive high fives request anymore" << std::endl;
}
