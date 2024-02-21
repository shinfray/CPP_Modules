/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:05 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:32:29 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <string>

# include "Weapon.hpp"

class HumanB {
    public:
        HumanB(const std::string& name);

        ~HumanB();

        const std::string&  getName() const;
        std::string         getWeapon() const;
        void        setWeapon(Weapon& weapon);
        void        attack() const;

    private:
        const std::string   name_;
        Weapon*             weapon_;
};

#endif  // HUNANB_HPP_
