/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:50:22 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 13:20:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const Intern::func  Intern::func_ptr_[3] = {&Intern::makePresidentialPardonForm, 
                                            &Intern::makeRobotomyRequestForm, 
                                            &Intern::makeShrubberyCreationForm};
const std::string   Intern::form_names_[3] = {"presidential pardon", 
                                              "robotomy request", 
                                              "shrubbery creation"};

const char* Intern::UnknownFormException::what() const throw()
{
    return "the form doesn't exist";
}

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm*  Intern::makeForm(const std::string &form, const std::string &target) const
{
    for (size_t i = 0; i < 3; ++i) {
        if (form_names_[i] == form) {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*func_ptr_[i])(target);
        }
    }
    throw UnknownFormException();
}

AForm*  Intern::makePresidentialPardonForm(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeRobotomyRequestForm(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makeShrubberyCreationForm(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}
