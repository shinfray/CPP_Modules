/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:23:27 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:18:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap Parametized constructor for " << getName() << std::endl;
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
    std::cout << "ScavTrap Copy constructor from " << src.getName() << std::endl;
    *this = src;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap Copy assignment constructor from " << rhs.getName() << std::endl;
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setMaxHitPoints(rhs.getMaxHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Default destructor for " << getName() << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() == 0) {
        std::cout << "ScavTrap " << getName();
        std::cout << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "ScavTrap " << getName();
        std::cout << " has no energy points left and cannot attack!";
        std::cout << std::endl;
        return;
    }
    --energy_points_;
    std::cout << "ScavTrap " << getName() << " attacks " << target;
    std::cout << ", causing " << getAttackDamage() << " points of damage!";
    std::cout << std::endl;
}

void    ScavTrap::guardGate()
{
    if (getHitPoints() > 0)
        std::cout << "ScavTrap is now in Gate Keeper mode" << std::endl;
    else
        std::cout << "ScavTrap is dead and can't be in Gate Keeper mode anymore" << std::endl;
}
