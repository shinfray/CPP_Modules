/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:58:08 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 18:02:55 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap	billy("Billy");
    ScavTrap	sophie("Sophie");

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

    return 0;
}
