/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:48:39 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 15:50:23 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP_
# define I_MATERIA_SOURCE_HPP_

# include <string>

# include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}

        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const & type) = 0;
};

#endif  // I_MATERIA_SOURCE_HPP_
