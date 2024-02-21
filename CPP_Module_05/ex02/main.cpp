/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:18:46 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/21 20:47:55 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    
    Bureaucrat  john("John", 1);
	Bureaucrat	bob("Bob", 73 );
	Bureaucrat	marc("Marc", 147);
	AForm		*shrub_form = new ShrubberyCreationForm("trees");
	AForm		*robot_form = new RobotomyRequestForm("Robots");
	AForm		*presid_form = new PresidentialPardonForm("Killer");

	std::cout << std::endl;
	std::cout << john << std::endl;
	std::cout << bob << std::endl;
	std::cout << marc << std::endl;
	std::cout << *shrub_form << std::endl;
	std::cout << *robot_form << std::endl;
	std::cout << *presid_form << std::endl << std::endl;

	try {
		std::cout << "=============== tests ============" << std::endl << std::endl;

		std::cout << "TRY TO SIGN: MARC" << std::endl << std::endl;
		marc.signForm(*shrub_form);
		marc.signForm(*robot_form);
		marc.signForm(*presid_form);
        std::cout << std::endl;
		std::cout << "TRY TO SIGN: BOB" << std::endl << std::endl;
		bob.signForm(*shrub_form);
		bob.signForm(*robot_form);
		std::cout << "PROMOTION OF BOB" << std::endl;
		bob.promote();
		bob.signForm(*robot_form);
		bob.signForm(*presid_form);
        std::cout << std::endl;
		std::cout << "TRY TO SIGN: JOHN" << std::endl << std::endl;
		john.signForm(*shrub_form);
		john.signForm(*robot_form);
		john.signForm(*presid_form);
		std::cout << std::endl;

		std::cout << "TRY TO EXECUTE: MARC" << std::endl << std::endl;
		marc.executeForm(*shrub_form);
		marc.executeForm(*robot_form);
		marc.executeForm(*presid_form);
		std::cout << std::endl;
		std::cout << "TRY TO EXECUTE: BOB" << std::endl << std::endl;
		bob.executeForm(*shrub_form);
		bob.executeForm(*robot_form);
		bob.executeForm(*presid_form);
		std::cout << std::endl;
		std::cout << "TRY TO EXECUTE: JOHN" << std::endl << std::endl;
		john.executeForm(*shrub_form);
		john.executeForm(*robot_form);
		john.executeForm(*presid_form);
	}
	catch (std::exception &e) {
		std::cout << std::endl << "ERROR: " << e.what() << std::endl;
        std::cout << std::endl;
	}

	delete shrub_form;
	delete robot_form;
	delete presid_form;

    return 0;
}
