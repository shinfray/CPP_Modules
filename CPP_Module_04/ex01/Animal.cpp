/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:20:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:33:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal")
{
    std::cout << "Default Animal constructor for " << getType() << std::endl;
}

Animal::Animal(const std::string& new_type) : type(new_type)
{
    std::cout << "Default Animal parametized constructor for " << getType() << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Default Animal copy constructor from " << src.getType() << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Default Animal copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs)
        this->setType(rhs.getType());
    return *this;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor for " << getType() << std::endl;
}

const std::string&  Animal::getType() const
{
    return type;
}

void    Animal::setType(const std::string& new_type)
{
    type = new_type;
}

void    Animal::makeSound() const
{
    std::cout << "Default sound for Animal" << std::endl;
}
