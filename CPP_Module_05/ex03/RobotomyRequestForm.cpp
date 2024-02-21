/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:56:32 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/22 01:55:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

bool    RobotomyRequestForm::seeded;

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("robotomy request", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), target_(src.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string&  RobotomyRequestForm::getTarget() const
{
    return (target_);
}

void    RobotomyRequestForm::applyExecution() const
{
    std::cout << "DDZZZZZZZZZZzzzzzzzzz, DDDZZZZZz, .... DZZZZZZZZZZZZZZzzzz";
    std::cout << std::endl;
    if (seeded == false) {
        std::srand((unsigned int)time(NULL));
        seeded = true;
    }
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully.";
    else
        std::cout << "The robotomy failed.";
    std::cout << std::endl;
}
