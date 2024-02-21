/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:58:08 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/15 16:27:45 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap	billy("Billy");
    ClapTrap	sophie("Sophie");

    // billy.setAttackDamage(3);
    // sophie.setAttackDamage(2);

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

    return 0;
}
