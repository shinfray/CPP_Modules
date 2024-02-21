/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:49:48 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 13:20:07 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
# define INTERN_HPP_

# include <exception>
# include <string>

# include "AForm.hpp"

class AForm;

class Intern {
    public:
        class UnknownFormException;

        Intern();

        ~Intern();

        AForm*  makeForm(const std::string& form, const std::string& target) const;
    
    private:
        typedef AForm*  (Intern::*func)(const std::string&) const;

        static const func        func_ptr_[3];
        static const std::string form_names_[3];

        Intern(const Intern& src);
        Intern& operator=(const Intern& rhs);

        AForm*  makePresidentialPardonForm(const std::string& target) const;
        AForm*  makeRobotomyRequestForm(const std::string& target) const;
        AForm*  makeShrubberyCreationForm(const std::string& target) const;

};

class Intern::UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
};

#endif  // INTERN_HPP_
