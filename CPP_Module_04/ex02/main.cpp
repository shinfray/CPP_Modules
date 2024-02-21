/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 11:28:16 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        Cat a;
        // Animal  b;   Should not compile

        a.makeSound();
        // b.makeSound();   Should not compile
    }

    std::cout << "=======================" << std::endl;

    {
        Cat*    a = new Cat();
        Animal*    b = new Cat();
        // Animal*    c = new Animal(); shoud not compile

        a->makeSound();
        b->makeSound();

        delete a;
        delete b;
    }
    
    return 0;
}
