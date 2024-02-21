/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:48:11 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 13:05:51 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP_
# define SHRUBBERY_CREATION_FORM_HPP_

# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);

        virtual ~ShrubberyCreationForm();

        const std::string&  getTarget() const;

    protected:
        virtual void        applyExecution() const;

    private:
        ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

        const std::string   target_;
};

#endif  // SHRUBBERY_CREATION_FORM_HPP_
