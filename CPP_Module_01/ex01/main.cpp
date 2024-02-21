/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:30:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:15:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moar_brainz.hpp"

int main()
{
	const int   n(4);
	Zombie*     zombie_horde(zombieHorde(n, "Eric"));
	
	for (int i(0); i < n; ++i)
		zombie_horde[i].announce();
	delete [] zombie_horde;
	return 0;
}
