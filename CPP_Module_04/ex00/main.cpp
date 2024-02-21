/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:30:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "=========================" << std::endl;
        const Animal*   meta = new Animal();
        std::cout << "=========================" << std::endl;
        const Animal*   j = new Dog();
        std::cout << "=========================" << std::endl;
        const Animal*   i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        std::cout << "=========================" << std::endl;

        delete meta;
        delete i;
        delete j;
    }

    {
        std::cout << "=========================" << std::endl;
        const WrongAnimal*   meta = new WrongAnimal();

        std::cout << "=========================" << std::endl;
        const WrongAnimal*   i = new WrongCat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        meta->makeSound();
        i->makeSound(); // output the WrongAnimal sound!

        std::cout << "=========================" << std::endl;

        delete meta;
        delete i;
    }

    return 0;
}
