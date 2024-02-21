/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:02:48 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:17 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Default Cure constructor" << std::endl;
}

Cure::~Cure()
{
    // std::cout << "Default Cure destructor" << std::endl;
}

AMateria*   Cure::clone() const
{
    return new Cure();
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
