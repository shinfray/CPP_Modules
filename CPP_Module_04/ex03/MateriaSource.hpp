/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:55:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 11:00:52 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP_
# define MATERIA_SOURCE_HPP_

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource&  operator=(const MateriaSource& rhs);

        virtual ~MateriaSource();

        virtual void        learnMateria(AMateria*);
        virtual AMateria*   createMateria(const std::string& type);

    private:
        AMateria*   materias_[4];
};


#endif  // MATERIA_SOURCE_HPP_