/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:33:27 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:17:46 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : name_("<undefined name>"), hit_points_(10),
      max_hit_points_(10), energy_points_(10),
      attack_damage_(0)
{
    std::cout << "ClapTrap Default constructor for " << getName() << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hit_points_(10), max_hit_points_(10), energy_points_(10),
      attack_damage_(0)
{
    std::cout << "ClapTrap Parametized constructor for " << getName() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "ClapTrap Copy constructor from " << src.getName() << std::endl;
    *this = src;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap Copy assignment constructor from " << rhs.getName() << std::endl;
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setMaxHitPoints(rhs.getMaxHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Default destructor for " << getName() << std::endl;
}

const std::string&  ClapTrap::getName() const
{
    return name_;
}

unsigned int    ClapTrap::getHitPoints() const
{
    return hit_points_;
}

unsigned int    ClapTrap::getMaxHitPoints() const
{
    return max_hit_points_;
}

unsigned int    ClapTrap::getEnergyPoints() const
{
    return energy_points_;
}

unsigned int    ClapTrap::getAttackDamage() const
{
	return attack_damage_;
}

void    ClapTrap::setName(const std::string& name)
{
    name_ = name;
}

void    ClapTrap::setHitPoints(const unsigned int hit_points)
{
    hit_points_ = hit_points;
}

void    ClapTrap::setMaxHitPoints(const unsigned int max_hit_points)
{
    max_hit_points_ = max_hit_points;
}

void    ClapTrap::setEnergyPoints(const unsigned int energy_points)
{
    energy_points_ = energy_points;
}

void    ClapTrap::setAttackDamage(const unsigned int attack_damage)
{
    attack_damage_ = attack_damage;
}

void    ClapTrap::displayStats() const
{
    std::cout << "[ " << getName() << " ]" << std::endl;
    std::cout << "Hit points: " << getHitPoints()  << std::endl;
    std::cout << "Energy points: " << getEnergyPoints()  << std::endl;
    std::cout << "Attack damage: " << getAttackDamage() << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (getHitPoints() == 0) {
        std::cout << "ClapTrap " << getName();
        std::cout << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "ClapTrap " << getName();
        std::cout << " has no energy points left and cannot attack!";
        std::cout << std::endl;
        return;
    }
    --energy_points_;
    std::cout << "ClapTrap " << getName() << " attacks " << target;
    std::cout << ", causing " << getAttackDamage() << " points of damage!";
    std::cout << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0) {
        std::cout << getName();
        std::cout << " is already dead and can't take any more damage!";
        std::cout << std::endl;
        return;
    }
    if (amount > getHitPoints())
        amount = getHitPoints();
    hit_points_ -= amount;
    std::cout << getName();
    std::cout << " has taken " << amount << " damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() == 0) {
        std::cout << getName();
        std::cout << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << getName();
        std::cout << " has no energy points left and cannot be repaired!";
        std::cout << std::endl;
        return;
    }
    int64_t total_hit_points((int64_t)(getHitPoints() + amount));
    if (total_hit_points > (int64_t)getMaxHitPoints()) {
        amount = getMaxHitPoints() - getHitPoints();
    }
    hit_points_ += amount;
    --energy_points_;
    std::cout << getName();
    std::cout << " has regained " << amount << " hit points!" << std::endl;
}
