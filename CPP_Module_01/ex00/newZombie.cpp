/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:04 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/11 20:28:49 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainz.hpp"

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}
