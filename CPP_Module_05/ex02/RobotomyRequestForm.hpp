/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:54:24 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 12:59:28 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP_
# define ROBOTOMY_REQUEST_FORM_HPP_

# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);

        virtual ~RobotomyRequestForm();

        const std::string&  getTarget() const;

    protected:
        virtual void        applyExecution() const;

    private:
        static bool seeded;

        RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

        const std::string   target_;
};

#endif  // ROBOTOMY_REQUEST_FORM_HPP_
