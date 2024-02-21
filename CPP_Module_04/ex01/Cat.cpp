/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:27:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:33:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor for " << getType() << std::endl;
    cat_brain = new Brain();
}

Cat::Cat(const std::string new_ideas[Brain::kTotalIdeas])
{
    std::cout << "Default Cat parametized constructor for " << getType() << std::endl;
    cat_brain = new Brain(new_ideas);
}

Cat::Cat(const Cat& src) : cat_brain(NULL)
{
    std::cout << "Default Cat copy constructor from " << src.getType() << std::endl;
    *this = src;
}

Cat&    Cat::operator=(const Cat& rhs)
{
    std::cout << "Default Cat copy assignement constructor from " << rhs.getType() << std::endl;
    if (this != &rhs) {
        this->setType(rhs.getType());
        delete this->cat_brain;
        this->cat_brain = new Brain(*rhs.cat_brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor for " << getType() << std::endl;
    delete cat_brain;
}

void    Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

void    Cat::displayIdeas() const
{
    cat_brain->displayIdeas();
}
