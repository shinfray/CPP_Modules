/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:00:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/21 12:38:49 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        static const int    kHighestGrade = 1;
        static const int    kLowestGrade = 150;

        class FormException;
        class GradeTooHighException;
        class GradeTooLowException;
        class AlreadySignedException;

        Form(const std::string& name, const int grade_to_sign, const int grade_to_execute);
        Form(const Form& src);

        ~Form();

        const std::string&  getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getIsSigned() const;
        void                beSigned(const Bureaucrat& bureaucrat);

    private:
        Form();
        Form&   operator=(const Form& rhs);

        bool    isTooLowGrade(const int grade) const;
        bool    isTooHighGrade(const int grade) const;
        bool    isAuthorisedToSign(const Bureaucrat& bureaucrat) const;
        bool    isAuthorisedToExecute(const Bureaucrat& bureaucrat) const;

        const std::string   name_;
        const int           grade_to_sign_;
        const int           grade_to_execute_;
        bool                is_signed_;
};

class Form::FormException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Form::GradeTooHighException : public FormException {
    public:
        virtual const char* what() const throw();
};

class Form::GradeTooLowException : public FormException {
    public:
        virtual const char* what() const throw();
};

class Form::AlreadySignedException : public FormException {
    public:
        virtual const char* what() const throw();
};

std::ostream&   operator<<(std::ostream& o, const Form& rhs);

#endif  // FORM_HPP_
