/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:58:54 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:33:57 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP_
# define I_CHARACTER_HPP_

# include <string>

# include "AMateria.hpp"

class AMateria;

class ICharacter {
    public:
        virtual ~ICharacter() {}

        virtual std::string const&  getName() const = 0;
        virtual void                equip(AMateria* m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif  // I_CHARACTER_HPP_
