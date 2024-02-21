/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:19:43 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:03 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <exception>
# include <string>

class Bureaucrat {
    public:
        static const int    kHighestGrade = 1;
        static const int    kLowestGrade = 150;

        class BureaucratException;
        class GradeTooHighException;
        class GradeTooLowException;

        Bureaucrat(const std::string& name, const int grade);
        Bureaucrat(const Bureaucrat& src);

        ~Bureaucrat();

        const std::string&  getName() const;
        int                 getGrade() const;
        void                promote();
        void                demote();

    private:
        Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& rhs);

        bool    isTooLowGrade(const int grade) const;
        bool    isTooHighGrade(const int grade) const;

        const std::string   name_;
        int                 grade_;
};

class Bureaucrat::BureaucratException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Bureaucrat::GradeTooHighException : public BureaucratException {
    public:
        virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public BureaucratException {
    public:
        virtual const char* what() const throw();
};
 
std::ostream&   operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif  // BUREAUCRAT_HPP_
