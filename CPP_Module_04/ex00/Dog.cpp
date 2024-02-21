/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:38:40 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:26:09 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog constructor for " << getType() << std::endl;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Default Dog copy constructor from " << src.getType() << std::endl;
    *this = src;
}

Dog&    Dog::operator=(const Dog& rhs)
{
    std::cout << "Default Dog copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs)
        this->setType(rhs.getType());
    return *this;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor for " << getType() << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
