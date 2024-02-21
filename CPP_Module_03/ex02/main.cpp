/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:58:08 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/15 18:50:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap	billy("Billy");
    FragTrap	sophie("Sophie");

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
    
    billy.highFivesGuys();
    sophie.highFivesGuys();

    return 0;
}
