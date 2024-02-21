/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:22:57 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:59:22 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP_
# define ICE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
    public:
        Ice();
        
        virtual ~Ice();

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);

    private:
        Ice(const Ice& src);
        Ice&    operator=(const Ice& rhs);
};

#endif  // ICE_HPP_
