/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:08 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 12:48:30 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

const char* Form::FormException::what() const throw()
{
    return "something went wrong with your form!";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "the grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "the grade is too low!";
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "the form already signed!";
}

Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_execute)
    : name_(name), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute), is_signed_(false)
{
    if (isTooHighGrade(grade_to_sign) == true || isTooHighGrade(grade_to_execute) == true)
        throw GradeTooHighException();
    if (isTooLowGrade(grade_to_sign) == true || isTooLowGrade(grade_to_execute) == true)
        throw GradeTooLowException();
}

Form::Form(const Form& src)
    : name_(src.getName()), grade_to_sign_(src.getGradeToSign()),
      grade_to_execute_(src.getGradeToExecute()), is_signed_(src.getIsSigned())
{
}

Form::~Form()
{
}

const std::string&  Form::getName() const
{
    return name_;
}

int Form::getGradeToSign() const
{
    return grade_to_sign_;
}

int Form::getGradeToExecute() const
{
    return grade_to_execute_;
}

bool    Form::getIsSigned() const
{
    return is_signed_;
}

bool    Form::isTooHighGrade(const int grade) const
{
    return grade < kHighestGrade;
}

bool    Form::isTooLowGrade(const int grade) const
{
    return grade > kLowestGrade;
}

bool    Form::isAuthorisedToSign(const Bureaucrat& bureaucrat) const
{
    return getGradeToSign() >= bureaucrat.getGrade();
}

bool    Form::isAuthorisedToExecute(const Bureaucrat& bureaucrat) const
{
    return getGradeToExecute() >= bureaucrat.getGrade();
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (getIsSigned() == true)
        throw AlreadySignedException();
    if (isAuthorisedToSign(bureaucrat) == false)
        throw GradeTooLowException();
    is_signed_ = true;
}

std::ostream&   operator<<(std::ostream& o, const Form& rhs)
{
    std::string sign_status;
    if (rhs.getIsSigned() == true)
        sign_status = "signed";
    else
        sign_status = "unsigned";

    return (o << "Form " << rhs.getName()
            << ", grade to sign: " << rhs.getGradeToSign()
            << ", grade to execute: " << rhs.getGradeToExecute()
            << ", status: " << sign_status);
}
