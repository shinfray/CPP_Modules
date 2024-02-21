/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:56:27 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:20 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Default Ice constructor" << std::endl;
}

Ice::~Ice()
{
    // std::cout << "Default Ice destructor" << std::endl;
}

AMateria*   Ice::clone() const
{
    return new Ice();
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
