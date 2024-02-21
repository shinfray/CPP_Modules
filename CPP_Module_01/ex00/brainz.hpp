/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainz.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:54 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/11 20:28:22 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINZ_HPP_
# define BRAINZ_HPP_

# include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif  // BRAINZ_HPP_
