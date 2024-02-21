/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:31:17 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:15:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "brainz.hpp"

int main()
{
	std::cout << "=======ZOMBIES ON STACK:" << std::endl;
	Zombie  first_on_stack("Joe");
    Zombie  second_on_stack("Mary");
    Zombie  third_on_stack("Sofia");
	first_on_stack.announce();
	second_on_stack.announce();
	third_on_stack.announce();

	std::cout << "=======ZOMBIES ON STACK WITH RANDOMCHUMP:" << std::endl;
	randomChump("Harry");
	randomChump("Marc");
	randomChump("Arthur");

	std::cout << "=======ZOMBIES ON HEAP:" << std::endl;
	Zombie* first_on_heap = new Zombie("Billy");
	first_on_heap->announce();
	Zombie* second_on_heap = new Zombie("Alex");
	second_on_heap->announce();
	Zombie* third_on_heap = new Zombie("Lily");
	third_on_heap->announce();

	delete first_on_heap;
	delete second_on_heap;
	delete third_on_heap;

	return 0;
}
