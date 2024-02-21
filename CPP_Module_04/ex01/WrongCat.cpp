/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:27:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:26:37 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructor for " << getType() << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
    std::cout << "Default WrongCat copy constructor from " << src.getType() << std::endl;
    *this = src;
}

WrongCat&    WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "Default WrongCat copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs)
        this->setType(rhs.getType());
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor for " << getType() << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongMeow!" << std::endl;
}
