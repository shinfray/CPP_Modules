/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:08 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/21 12:37:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

const char* AForm::AFormException::what() const throw()
{
    return "something went wrong with your form!";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "the grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "the grade is too low!";
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "the form already signed!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "the form is not signed!";
}

AForm::AForm(const std::string& name, const int grade_to_sign, const int grade_to_execute)
    : name_(name), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute), is_signed_(false)
{
    if (isTooHighGrade(grade_to_sign) == true || isTooHighGrade(grade_to_execute) == true)
        throw GradeTooHighException();
    if (isTooLowGrade(grade_to_sign) == true || isTooLowGrade(grade_to_execute) == true)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : name_(src.getName()), grade_to_sign_(src.getGradeToSign()),
      grade_to_execute_(src.getGradeToExecute()), is_signed_(src.getIsSigned())
{
}

AForm::~AForm()
{
}

const std::string&  AForm::getName() const
{
    return name_;
}

int                 AForm::getGradeToSign() const
{
    return grade_to_sign_;
}

int                 AForm::getGradeToExecute() const
{
    return grade_to_execute_;
}

bool                AForm::getIsSigned() const
{
    return is_signed_;
}

bool    AForm::isTooHighGrade(const int grade) const
{
    return grade < kHighestGrade;
}

bool    AForm::isTooLowGrade(const int grade) const
{
    return grade > kLowestGrade;
}

bool    AForm::isAuthorisedToSign(const Bureaucrat& bureaucrat) const
{
    return getGradeToSign() >= bureaucrat.getGrade();
}

bool    AForm::isAuthorisedToExecute(const Bureaucrat& bureaucrat) const
{
    return getGradeToExecute() >= bureaucrat.getGrade();
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (getIsSigned() == true)
        throw AlreadySignedException();
    if (isAuthorisedToSign(bureaucrat) == false)
        throw GradeTooLowException();
    is_signed_ = true;
}

void    AForm::execute(const Bureaucrat& executor) const
{
    if (getIsSigned() == false)
        throw NotSignedException();
    if (isAuthorisedToExecute(executor) == false)
        throw GradeTooLowException();
    applyExecution();
}

std::ostream&   operator<<(std::ostream& o, const AForm& rhs)
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
