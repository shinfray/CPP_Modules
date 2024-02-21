/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 10:48:42 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const int   array_size = 4;

    Animal* animal_array[array_size];
    for (int i = 0; i < array_size / 2; ++i)
        animal_array[i] = new Dog();
    std::cout << "============================" << std::endl;
    for (int i = array_size / 2; i < array_size; ++i)
        animal_array[i] = new Cat();
    std::cout << "============================" << std::endl;
    for (int i = 0; i < array_size; ++i)
        delete animal_array[i];
    
    std::cout << "++++++++++++++++++++++++++++++++" << std::endl;

    const Animal*   i = new Cat();
    const Animal*   j = new Dog();

    delete i;
    delete j;//should not create a leak

    std::cout << "--------------------------------" << std::endl;

    const std::string   thoughts[Brain::kTotalIdeas] =
        {"I'm Hungry",
         "Now, I'm very Hungry",
         "I'm bored..."};

    const Cat*  k = new Cat(thoughts);
    std::cout << "-------a" << std::endl;
    const Cat*  l = new Cat(*k);
    std::cout << "-------b" << std::endl;
    delete k;
    std::cout << "-------c" << std::endl;

    // k->displayIdeas();
    l->displayIdeas();

    delete l;

    return 0;
}
