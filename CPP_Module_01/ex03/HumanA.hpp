/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:00 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:27:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
# define HUMANA_HPP_

# include <string>
# include "Weapon.hpp"

class HumanA {
    public:
        HumanA(const std::string& name, Weapon& weapon);

        ~HumanA();

        const std::string&  getName() const;
        const std::string&  getWeapon() const;
        void        attack() const;

    private:
        const std::string   name_;
        Weapon&             weapon_;
};

#endif  // HUMANA_HPP_
