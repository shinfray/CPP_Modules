/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:56:10 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:43:11 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP_
# define A_MATERIA_HPP_

# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria {
    public:
        AMateria(const std::string& type);

        virtual ~AMateria();

        const std::string&  getType() const;
        
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);

    protected:
        const std::string   type_;

    private:
        AMateria();
        AMateria(const AMateria& src);
        AMateria&   operator=(const AMateria& rhs);
};

#endif  // A_MATERIA_HPP_
