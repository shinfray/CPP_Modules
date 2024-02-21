/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:19:29 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 12:40:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

const char* Bureaucrat::BureaucratException::what() const throw()
{
    return "something went wrong with your bureaucrat!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "the grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "the grade is too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade)
{
    if (isTooHighGrade(grade) == true)
        throw GradeTooHighException();
    if (isTooLowGrade(grade) == true)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name_(src.getName()), grade_(src.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&  Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}
void    Bureaucrat::promote()
{
    if (isTooHighGrade(getGrade() - 1) == true)
        throw Bureaucrat::GradeTooHighException();
    --grade_;
    std::cout << "Promotion accepted!" << std::endl;
}

void    Bureaucrat::demote()
{
    if (isTooLowGrade(getGrade() + 1) == true)
        throw Bureaucrat::GradeTooLowException();
    ++grade_;
    std::cout << "Demotion accepted!" << std::endl;
}

void    Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (const Form::FormException& e)
    {
        std::cout << getName() << " couldn't sign " << form.getName();
        std::cout << " because " << e.what() << std::endl;
    }
}

bool    Bureaucrat::isTooHighGrade(const int grade) const
{
    return grade < kHighestGrade;
}

bool    Bureaucrat::isTooLowGrade(const int grade) const
{
    return grade > kLowestGrade;
}

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& rhs)
{
    return o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}
