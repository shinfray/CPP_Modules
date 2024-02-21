/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:06:15 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:20:33 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP_
# define FRAG_TRAP_HPP_

# include <string>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& src);
        FragTrap&   operator=(const FragTrap& rhs);

        ~FragTrap();

        void    highFivesGuys();
};

#endif  // FRAG_TRAP_HPP_
