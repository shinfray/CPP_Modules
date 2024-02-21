/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:13 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:24:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon {
    public:
        Weapon(const std::string& weapon);

        ~Weapon();

        const std::string&  getType() const;
        void                setType(const std::string& weapon);

    private:
        std::string type_;
};

#endif  // WEAPON_HPP_
