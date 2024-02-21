/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:40:52 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 11:04:37 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character() : name_("<undefined name>")
{
    // std::cout << "Default Character constructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        inventory_[i] = NULL;
}

Character::Character(const std::string& name) : name_(name)
{
    // std::cout << "Default Character parametized constructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        inventory_[i] = NULL;
}

Character::Character(const Character& src)
{
    // std::cout << "Default Character copy constructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        inventory_[i] = NULL;
    *this = src;
}

Character&  Character::operator=(const Character& rhs)
{
    // std::cout << "Default Character copy assignement constructor" << std::endl;
    if (this == &rhs)
        return *this;
    this->name_ = rhs.getName();
    for (size_t i = 0; i < 4; ++i) {
        if (rhs.inventory_[i] != NULL) {
            delete this->inventory_[i];
            this->inventory_[i] = rhs.inventory_[i]->clone();
        } else {
            this->unequip(i);
        }
    }
    return *this;
}

Character::~Character()
{
    // std::cout << "Default Character destructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        delete inventory_[i];
}

const std::string&  Character::getName() const
{
    return (name_);
}

void    Character::equip(AMateria* m)
{
    for (size_t i = 0; i < 4; ++i) {
        if (inventory_[i] == NULL) {
            inventory_[i] = m;
            std::cout << "Materia equiped at index " << i << " for " << getName() << std::endl;
            return;
        }
    }
    std::cout << getName() << "'s inventory is full!" << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory_[idx] != NULL) {
        inventory_[idx] = NULL;
        std::cout << "Materia at index " << idx << " unequiped for " << getName() << std::endl;
    } else {
        std::cout << "There is nothing to unequiped at inventory index " << idx << " for " << getName() << std::endl;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory_[idx] != NULL)
        inventory_[idx]->use(target);
    else
        std::cout << "There is nothing to use at inventory index " << idx << " for " << getName() << std::endl;
}
