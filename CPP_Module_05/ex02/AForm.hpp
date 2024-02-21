/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:00:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/21 11:59:36by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
# define AFORM_HPP_

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        static const int    kHighestGrade = 1;
        static const int    kLowestGrade = 150;

        class AFormException;
        class GradeTooHighException;
        class GradeTooLowException;
        class AlreadySignedException;
        class NotSignedException;

        AForm(const std::string& name, const int grade_to_sign, const int grade_to_execute);
        AForm(const AForm& src);

        virtual ~AForm();

        const std::string&  getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getIsSigned() const;
        void                beSigned(const Bureaucrat& bureaucrat);
        void                execute(const Bureaucrat& executor) const;

    protected:
        virtual void        applyExecution() const = 0;

    private:
        AForm();
        AForm&   operator=(const AForm& rhs);

        bool    isTooLowGrade(const int grade) const;
        bool    isTooHighGrade(const int grade) const;
        bool    isAuthorisedToSign(const Bureaucrat& bureaucrat) const;
        bool    isAuthorisedToExecute(const Bureaucrat& bureaucrat) const;

        const std::string   name_;
        const int           grade_to_sign_;
        const int           grade_to_execute_;
        bool                is_signed_;
};

class AForm::AFormException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class AForm::GradeTooHighException : public AFormException {
    public:
        virtual const char* what() const throw();
};

class AForm::GradeTooLowException : public AFormException {
    public:
        virtual const char* what() const throw();
};

class AForm::AlreadySignedException : public AFormException {
    public:
        virtual const char* what() const throw();
};
class AForm::NotSignedException : public AFormException {
    public:
        virtual const char* what() const throw();
};

std::ostream&   operator<<(std::ostream& o, const AForm& rhs);

#endif  // AFORM_HPP_
