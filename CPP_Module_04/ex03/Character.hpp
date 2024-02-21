/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:38:40 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:57:22 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& src);
        Character&  operator=(const Character& rhs);

        virtual ~Character();

        virtual const std::string&  getName() const;
        virtual void                equip(AMateria* m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);

    private:
        std::string name_;
        AMateria*   inventory_[4];
};

#endif  // CHARACTER_HPP_
