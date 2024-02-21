/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:38:40 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:33:50 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog constructor for " << getType() << std::endl;
    dog_brain = new Brain();
}

Dog::Dog(const std::string new_ideas[Brain::kTotalIdeas])
{
    std::cout << "Default Dog parametized constructor for " << getType() << std::endl;
    dog_brain = new Brain(new_ideas);
}

Dog::Dog(const Dog& src) : dog_brain(NULL)
{
    std::cout << "Default Dog copy constructor from " << src.getType() << std::endl;
    *this = src;
}

Dog&    Dog::operator=(const Dog& rhs)
{
    std::cout << "Default Dog copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs) {
        this->setType(rhs.getType());
        delete this->dog_brain;
        this->dog_brain = new Brain(*rhs.dog_brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor for " << getType() << std::endl;
    delete dog_brain;
}

void    Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void    Dog::displayIdeas() const
{
    dog_brain->displayIdeas();
}
