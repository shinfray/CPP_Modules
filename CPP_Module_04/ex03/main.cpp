/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:41:28 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/18 17:27:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria*   tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << std::endl << "=====================================" << std::endl << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    AMateria*   tmp;

    me->use(0, *bob);
    tmp = src->createMateria("blabla");
    me->equip(tmp);
    me->use(0, *bob);

    std::cout << std::endl << "=====================================" << std::endl << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob);
    me->unequip(0);
    me->use(0, *bob);
    delete tmp;
    tmp = NULL;

    std::cout << std::endl << "=====================================" << std::endl << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    delete tmp;
    tmp = NULL;

    std::cout << std::endl << "=====================================" << std::endl << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}
