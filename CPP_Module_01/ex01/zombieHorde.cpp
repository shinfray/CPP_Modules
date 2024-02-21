/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:18:44 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 16:21:50 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moar_brainz.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie* zombie_horde = new Zombie[n];
	for (int i = 0; i < n; ++i)
		zombie_horde[i].set_name(name);
	return zombie_horde;
}
