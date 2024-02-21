/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:07 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 16:22:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon  club("crude spiked club");
        HumanA  bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon  club("crude spiked club");
        HumanB  jim("Jim");

        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
