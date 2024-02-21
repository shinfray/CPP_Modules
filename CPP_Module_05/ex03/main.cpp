/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:18:46 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/23 00:08:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
	{
		std::cout << "========== TEST BAD FORM ============" << std::endl;
        std::cout << std::endl;

		Bureaucrat	billy("Billy", 10);
		std::cout << billy << std::endl;

		Intern	intern;
		AForm	*form = intern.makeForm("bad form", "Joe");

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR:" << e.what() << std::endl;
	}
	
	try
	{
        std::cout << std::endl;
		std::cout << "========== TEST GOOD FORM ============" << std::endl;
        std::cout << std::endl;

		Bureaucrat	Tom("Tom", 2);
		std::cout << Tom << std::endl;

		Intern	intern;
		AForm	*form = intern.makeForm("presidential pardon", "Julie");

		std::cout << *form << std::endl;
		Tom.signForm(*form);
		std::cout << *form << std::endl;
		Tom.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR:" << e.what() << std::endl;
	}

    return 0;
}
