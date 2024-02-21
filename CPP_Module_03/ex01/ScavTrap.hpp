/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:23:39 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:20:49 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP_
# define SCAV_TRAP_HPP_

# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& src);
        ScavTrap&   operator=(const ScavTrap& rhs);

        ~ScavTrap();

        void    attack(const std::string& target);
        void    guardGate();
};

#endif  // SCAV_TRAP_HPP_
