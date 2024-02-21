/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:45:58 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 13:05:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP_
# define PRESIDENTIAL_PARDON_FORM_HPP_

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);

        virtual ~PresidentialPardonForm();

        const std::string&  getTarget() const;

    protected:
        virtual void        applyExecution() const;

    private:
        PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

        const std::string   target_;
};

#endif  // PRESIDENTIAL_PARDON_FORM_HPP_
