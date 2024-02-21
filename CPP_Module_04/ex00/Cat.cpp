/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:27:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:25:49 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor for " << getType() << std::endl;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Default Cat copy constructor from " << src.getType() << std::endl;
    *this = src;
}

Cat&    Cat::operator=(const Cat& rhs)
{
    std::cout << "Default Cat copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs)
        this->setType(rhs.getType());
    return *this;
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor for " << getType() << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
