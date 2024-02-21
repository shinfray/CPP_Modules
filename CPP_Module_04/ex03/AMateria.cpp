/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:10:44 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:11:42 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(const std::string& type) : type_(type)
{
    // std::cout << "Default AMateria parametized constructor" << std::endl;
}

AMateria::~AMateria()
{
    // std::cout << "Default AMateria destructor" << std::endl;
}

const std::string&  AMateria::getType() const
{
    return (type_);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "* " <<  getType() << " used on " << target.getName() << " *" << std::endl;
}
