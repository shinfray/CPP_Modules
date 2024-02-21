/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:35:49 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:22:39 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP_
# define DIAMOND_TRAP_HPP_

# include <string>

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& src);
        DiamondTrap&   operator=(const DiamondTrap& rhs);

        ~DiamondTrap();

        const std::string&  getName() const;
        void                setName(const std::string& name);
        void                attack(const std::string& target);
        void                whoAmI();

    private:
        std::string name_;
};

#endif  // DIAMOND_TRAP_HPP_
