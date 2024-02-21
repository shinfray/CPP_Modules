/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:06 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:15:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainz.hpp"

void    randomChump(std::string name)
{
	Zombie  randomZombie(name);
	randomZombie.announce();
}
