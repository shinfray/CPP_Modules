/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:46:05 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/22 01:54:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("presidential pardon", 25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), target_(src.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string&  PresidentialPardonForm::getTarget() const
{
    return (target_);
}

void    PresidentialPardonForm::applyExecution() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.";
    std::cout << std::endl;
}
