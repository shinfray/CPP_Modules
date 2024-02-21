/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:14:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:58:04 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP_
# define CURE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
    public:
        Cure();
        
        virtual ~Cure();

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);

    private:
        Cure(const Cure& src);
        Cure&   operator=(const Cure& rhs);
};

#endif  // CURE_HPP_
