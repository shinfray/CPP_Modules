/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:01:27 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
    // std::cout << "Default MateriaSource constructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        materias_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    // std::cout << "Default MateriaSource copy constructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        materias_[i] = NULL;
    *this = src;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs)
{
    // std::cout << "Default MateriaSource copy assignement constructor" << std::endl;
    if (this != &rhs) {
        for (size_t i = 0; i < 4; ++i) {
            delete this->materias_[i];
            this->materias_[i] = rhs.materias_[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    // std::cout << "Default MateriaSource destructor" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        delete materias_[i];
}
 void   MateriaSource::learnMateria(AMateria* materia)
 {
    size_t  i = 0;
    for (; i < 4; ++i) {
        if (materias_[i] == NULL) {
            materias_[i] = materia;
            break;
        }
    }
    if (i == 4)
        delete materia;
 }

 AMateria*  MateriaSource::createMateria(const std::string& type)
 {
    for (size_t i = 0; i < 4; ++i)
        if (materias_[i] != NULL && materias_[i]->getType() == type)
            return materias_[i]->clone();
    return NULL;
 }
