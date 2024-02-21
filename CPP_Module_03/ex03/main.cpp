/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:58:08 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/15 14:51:12y shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=================billy=============" << std::endl;
    DiamondTrap	billy("Billy");
    std::cout << "=================sophie=============" << std::endl;
    DiamondTrap	sophie("Sophie");

    billy.displayStats();
    sophie.displayStats();

    billy.attack(sophie.getName());
    sophie.takeDamage(billy.getAttackDamage());

    billy.displayStats();
    sophie.displayStats();

    sophie.attack(billy.getName());
    billy.takeDamage(sophie.getAttackDamage());

    billy.displayStats();
    sophie.displayStats();

    billy.attack(sophie.getName());
    sophie.takeDamage(billy.getAttackDamage());

    billy.displayStats();
    sophie.displayStats();

    billy.beRepaired(2);
    sophie.beRepaired(2);

    billy.displayStats();
    sophie.displayStats();
    
    billy.guardGate();
    sophie.guardGate();

    billy.highFivesGuys();
    sophie.highFivesGuys();

    billy.attack(sophie.getName());
    sophie.whoAmI();

    return 0;
}
