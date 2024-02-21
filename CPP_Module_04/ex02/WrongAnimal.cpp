/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:20:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:26:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor for " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& new_type) : type(new_type)
{
    std::cout << "Default WrongAnimal parametized constructor for " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "Default WrongAnimal copy constructor from " << src.getType() << std::endl;
    *this = src;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "Default WrongAnimal copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs)
        this->setType(rhs.getType());
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor for " << getType() << std::endl;
}

const std::string&  WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::setType(const std::string& new_type)
{
    type = new_type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Default sound for WrongAnimal" << std::endl;
}
