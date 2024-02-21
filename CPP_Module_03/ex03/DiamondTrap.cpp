/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:36:48 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:21:57 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), name_("<name>")
{
    std::cout << "DiamondTrap Default constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), name_(name)
{
    std::cout << "DiamondTrap parametized constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
    std::cout << "DiamondTrap Copy constructor from " << src.getName() << std::endl;
    *this = src;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& rhs)
{
    std::cout << "DiamondTrap Copy assignment constructor from " << rhs.getName() << std::endl;
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->ClapTrap::setName(rhs.ClapTrap::getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setMaxHitPoints(rhs.getMaxHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;

}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor for " << getName() << std::endl;
}

const std::string&  DiamondTrap::getName() const
{
    return name_;
}

void    DiamondTrap::setName(const std::string& name)
{
    name_ = name;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << getName() << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
