/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:50:50 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/22 01:54:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("shrubbery creation", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), target_(src.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string&  ShrubberyCreationForm::getTarget() const
{
    return (target_);
}

void    ShrubberyCreationForm::applyExecution() const
{
    std::ofstream   shrubbery_file(getTarget() + "_shrubbery");

    std::string trees =
        "               ,@@@@@@@,                   \n"
        "       ,,,.   ,@@@@@@/@@,  .oo8888o.       \n"
        "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      \n"
        "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'     \n"
        "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'     \n"
        "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'      \n"
        "   `&%\\ ` /%&'    |.|        \\ '|8'        \n"
        "       |o|        | |         | |          \n"
        "       |.|        | |         | |          \n"
        "//_ \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_  \n";
    
    shrubbery_file << trees;
}
